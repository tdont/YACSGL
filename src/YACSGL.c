/******************************************************************************
 * COPYRIGHT (C) Guerwood 2022. All rights reserved.
 *****************************************************************************/

/******************** FILE HEADER ********************************************/
/**\addtogroup ModuleName_External_Documentation
 * \{ */
/**\addtogroup SubModuleName
 * \{ */

/**
 * \file YAGSGL.c
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 12 Aug. 2022
 */

/**
 * \cond INTERNAL_DOC
 *
 * \mainpage External documentation of module
 *
 * \section Description
 * This module does what you want him to do....
 *
 * \section Features
 * The main features of the module are described here.
 *
 * \endcond
 */

/******************** INCLUDES ***********************************************/
#include "YACSGL.h"
#include "YACSGL_pixel.h"

#include <string.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/
static inline void YACSGL_rect_line_width_height (YACSGL_frame_t* frame, 
                                                    uint16_t x_topleft_width, 
                                                    uint16_t y_topleft_height, 
                                                    uint16_t x_bottomright_width, 
                                                    uint16_t y_bottomright_height, 
                                                    YACSGL_pixel_t pixel, 
                                                    uint16_t step,
                                                    uint16_t step_corrector);

                                                    
static inline void YACSGL_rect_line_heigth_width (YACSGL_frame_t* frame, 
                                                    uint16_t x_topleft_width, 
                                                    uint16_t y_topleft_height, 
                                                    uint16_t x_bottomright_width, 
                                                    uint16_t y_bottomright_height, 
                                                    YACSGL_pixel_t pixel, 
                                                    uint16_t step,
                                                    uint16_t step_corrector);

/******************** API FUNCTIONS ******************************************/
static inline void YACSGL_set_pixel(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel)
{
    if (x_width >= frame->frame_x_width  || y_height >= frame->frame_y_heigth)
    {
        return;
    }

    /* Retrieve the byte where the pixel to be changed lies */
    uint8_t tmp_byte = *(frame->frame_buffer + x_width / 8 + (y_height * frame->frame_x_width / 8));
	// if (pixel == YACSGL_P_WHITE)
	// {
	//	tmp_byte |= pixel << (7 - (x_width %8));
	// }
	// else
	// {
	//	tmp_byte &= ~(pixel << (7 - (x_width %8)));
	// }
    tmp_byte |= pixel << (7 - (x_width %8));
    tmp_byte &= ~(((!pixel) & 0b1) << (7 - (x_width %8)));
	*(frame->frame_buffer + x_width / 8 + (y_height * frame->frame_x_width / 8)) = tmp_byte;
}

void YACSGL_rect_fill(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel)
{
    /* Try to be clever and optimize with memset for aligned area */
    /* Detect first aligned byte */
    uint16_t x_align_start = (x_topleft_width / 8);
    uint16_t x_remaining_before = (x_topleft_width % 8);
    uint8_t unable_to_memset = 0;
    uint16_t size_memset = 0;
    if(x_remaining_before)
    {
        x_align_start++;
    }

    /* Detect last aligned byte and complete */
    uint16_t x_align_end = (x_bottomright_width / 8);
    uint16_t x_remaining_after = (x_bottomright_width % 8);
    if(x_remaining_after)
    {
        if(x_align_end == x_align_start)
        {
            /* No memset possible are there is not a complete byte to be set*/
            unable_to_memset = 1;
        }
        x_align_end--;
    }

    /* If a memset can trully occur */
    if(unable_to_memset == 0)
    {
        int32_t delta_y = y_bottomright_height - y_topleft_height + 1; /* Compute how many line can be memset */
        uint8_t value_to_set = 0;
        if(pixel == YACSGL_P_WHITE)
        {
            value_to_set = 0xFF;
        }
        size_memset = x_align_end - x_align_start + 1;

        for(uint16_t i = 0; i < delta_y; i++)
        {
            memset(&frame->frame_buffer[x_align_start + ((i + y_topleft_height)) * (frame->frame_x_width / 8)], 
                    value_to_set, 
                    size_memset);
        }
    }

    /* Complete the missing area of the rectangle with vertical lines */
    for(uint16_t i = 0; i < (7 - x_remaining_before) ; i++)
    {
        YACSGL_line(frame, x_topleft_width +  7 - i, y_topleft_height, x_topleft_width + 7 - i, y_bottomright_height, pixel);
    }
    for(uint16_t i = 0; i < x_remaining_after; i++)
    {
        YACSGL_line(frame, 
                        x_topleft_width + x_remaining_before + (size_memset) * 8 + i, 
                        y_topleft_height, 
                        x_topleft_width + x_remaining_before + (size_memset) * 8 + i,
                        y_bottomright_height, pixel);
    }

    return;
}

void YACSGL_rect_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel)
{
    /* Draw the four line of the rectangle */
    /* Top horizontal line */
    YACSGL_line(frame, x_topleft_width, y_topleft_height, x_bottomright_width, y_topleft_height, pixel);
    /* Bottom horizontal line */
    YACSGL_line(frame, x_topleft_width, y_bottomright_height, x_bottomright_width, y_bottomright_height, pixel);

    /* Left vertical line */
    YACSGL_line(frame, x_topleft_width, y_topleft_height, x_topleft_width, y_bottomright_height, pixel);
    /* Rigth vertical line */
    YACSGL_line(frame, x_bottomright_width, y_topleft_height, x_bottomright_width, y_bottomright_height, pixel);


    return;
}   


void YACSGL_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel)
{
    int32_t delta_x = x_bottomright_width - x_topleft_width + 1;
    int32_t delta_y = y_bottomright_height - y_topleft_height + 1;

    uint16_t step = 0;
    uint16_t step_corrector = 0;
    uint16_t modulo = 0;

    if(delta_x < delta_y)
    {
        /* Detect a pure vertical line case */
        if (delta_x == 0)
        {
            step = delta_y;
            step_corrector = 0;
        }
        else        
        {
            
            step = delta_y / delta_x;       
            modulo = delta_y % delta_x;
            if(modulo == 0)
            {
                step_corrector = 0;
            }
            else
            {
                step_corrector = delta_y / modulo;   
            }
        }
        
        YACSGL_rect_line_heigth_width(frame, 
                                    x_topleft_width, 
                                    y_topleft_height, 
                                    x_bottomright_width, 
                                    y_bottomright_height, 
                                    pixel, 
                                    step,
                                    step_corrector);

    }
    else
    {
        /* Detect a pure horizontal line case */
        if (delta_y == 0)
        {
            step = delta_x;
            step_corrector = 0;
        }
        else       
        {            
            step = delta_x / delta_y;
            modulo = delta_x % delta_y;
            if(modulo == 0)
            {
                step_corrector = 0;
            }
            else
            {
                step_corrector = delta_x / modulo;
            }
        }        
        
        YACSGL_rect_line_width_height(frame, 
                                        x_topleft_width, 
                                        y_topleft_height, 
                                        x_bottomright_width, 
                                        y_bottomright_height, 
                                        pixel, 
                                        step,
                                        step_corrector);
    }
     

    return;
}  

void YACSGL_circle_fill(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel)
{
    return;
}

void YACSGL_circle_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel)
{
    return;
}                                

/******************** LOCAL FUNCTIONS ****************************************/
static inline void YACSGL_rect_line_width_height (YACSGL_frame_t* frame, 
                                                    uint16_t x_topleft_width, 
                                                    uint16_t y_topleft_height, 
                                                    uint16_t x_bottomright_width, 
                                                    uint16_t y_bottomright_height, 
                                                    YACSGL_pixel_t pixel, 
                                                    uint16_t step,
                                                    uint16_t step_corrector)
{
    uint16_t temp_x = x_topleft_width;
    uint16_t temp_y = y_topleft_height;

    uint16_t current_step = 1;

    do{
        /* Travel horizontally before stepping down */
        for (uint16_t i = 0; i < step; i++)
        {
            YACSGL_set_pixel(frame, temp_x,  temp_y, pixel);
            temp_x++;
            current_step++;
            if(step_corrector != 0 && current_step >= step_corrector)
            {
                current_step = 1;
                YACSGL_set_pixel(frame, temp_x,  temp_y, pixel);
                temp_x++;
            }        
        }        
        temp_y++;
    }
    while(temp_x < x_bottomright_width && temp_y <= y_bottomright_height);

    return;
}

static inline void YACSGL_rect_line_heigth_width (YACSGL_frame_t* frame, 
                                                    uint16_t x_topleft_width, 
                                                    uint16_t y_topleft_height, 
                                                    uint16_t x_bottomright_width, 
                                                    uint16_t y_bottomright_height, 
                                                    YACSGL_pixel_t pixel, 
                                                    uint16_t step,
                                                    uint16_t step_corrector)
{
    uint16_t temp_x = x_topleft_width;
    uint16_t temp_y = y_topleft_height;

    uint16_t current_step = 1;

    do{
        /* Travel vertically before stepping to the right */
        for (uint16_t i = 0; i < step; i++)
        {
            YACSGL_set_pixel(frame, temp_x,  temp_y, pixel);
            temp_y++;
            current_step++;
            if(step_corrector != 0 && current_step >= step_corrector)
            {
                current_step = 1;
                YACSGL_set_pixel(frame, temp_x,  temp_y, pixel);
                temp_y++;
            }    
        }
        temp_x++;
    }
    while(temp_x <= x_bottomright_width && temp_y < y_bottomright_height);
    
    return;
}


/**\} */
/**\} */

/* EOF */
