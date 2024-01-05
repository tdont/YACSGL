/******************************************************************************
* Copyright(c) 2022 Thibaut DONTAIL
*
* This file is part of YACSGL.
*
* YACSGL is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* YACSGL is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with YACSGL.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

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
typedef enum
{
    YACSGL_CIRCLE_LINE = 0,
    YACSGL_CIRCLE_FILL
}YACSGL_circle_type_e;

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/
static inline void YACSGL_set_pixel_no_offset(YACSGL_frame_t* frame,
                                              uint16_t x_width,
                                              uint16_t y_height,
                                              YACSGL_pixel_t pixel)
{
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
    tmp_byte |= pixel << (7 - (x_width % 8));
    tmp_byte &= ~(((!pixel) & 0b1) << (7 - (x_width % 8)));
    *(frame->frame_buffer + x_width / 8 + (y_height * frame->frame_x_width / 8)) = tmp_byte;
}

static void YACSGL_rect_fill_no_offset(YACSGL_frame_t* frame,
                                       uint16_t x_topleft_width,
                                       uint16_t y_topleft_height,
                                       uint16_t x_bottomright_width,
                                       uint16_t y_bottomright_height,
                                       YACSGL_pixel_t pixel);

static void YACSGL_rect_line_no_offset(YACSGL_frame_t* frame,
                                       uint16_t x_topleft_width,
                                       uint16_t y_topleft_height,
                                       uint16_t x_bottomright_width,
                                       uint16_t y_bottomright_height,
                                       YACSGL_pixel_t pixel);

static void YACSGL_circle_no_offset(YACSGL_frame_t* frame, 
                                    uint16_t x_u, 
                                    uint16_t y_u, 
                                    uint16_t radius_u, 
                                    YACSGL_pixel_t pixel,
                                    YACSGL_circle_type_e type);

static void YACSGL_line_no_offset(YACSGL_frame_t* frame,
                                  uint16_t x0,
                                  uint16_t y0,
                                  uint16_t x1,
                                  uint16_t y1,
                                  YACSGL_pixel_t pixel);

static void YACSGL_line_no_check_no_offset(YACSGL_frame_t* frame, 
                                           uint16_t x0, 
                                           uint16_t y0, 
                                           uint16_t x1, 
                                           uint16_t y1, 
                                           YACSGL_pixel_t pixel);
/******************** API FUNCTIONS ******************************************/
void YACSGL_set_pixel(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel)
{
    YACSGL_set_pixel_no_offset(frame, x_width + frame->offset_x, y_height + frame->offset_y, pixel);
}

void YACSGL_rect_fill(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel)
{
    if (frame == NULL)
    {
        return;
    }
    YACSGL_rect_fill_no_offset(frame, 
                               x_topleft_width + frame->offset_x,
                               y_topleft_height + frame->offset_y, 
                               x_bottomright_width + frame->offset_x, 
                               y_bottomright_height + frame->offset_y, 
                               pixel);
}

void YACSGL_rect_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel)
{
    if (frame == NULL)
    {
        return;
    }
    YACSGL_rect_line_no_offset(frame, 
                               x_topleft_width + frame->offset_x,
                               y_topleft_height + frame->offset_y, 
                               x_bottomright_width + frame->offset_x, 
                               y_bottomright_height + frame->offset_y, 
                               pixel);
}   

void YACSGL_line(YACSGL_frame_t* frame, 
                        uint16_t x0, 
                        uint16_t y0, 
                        uint16_t x1, 
                        uint16_t y1, 
                        YACSGL_pixel_t pixel)
{
    if (frame == NULL)
    {
        return;
    } 
    YACSGL_line_no_offset(frame, x0 + frame->offset_x, y0 + frame->offset_y, x1 + frame->offset_x, y1 + frame->offset_y, pixel);
}  

void YACSGL_circle_fill(YACSGL_frame_t* frame, 
                        uint16_t x, 
                        uint16_t y, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel)
{
    if (frame == NULL)
    {
        return;
    }
    YACSGL_circle_no_offset(frame, x + frame->offset_x, y + frame->offset_y, radius, pixel, YACSGL_CIRCLE_FILL);
    return;
}

/** \brief use of Breseham's algorithm */
void YACSGL_circle_line(YACSGL_frame_t* frame, 
                        uint16_t x, 
                        uint16_t y, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel)   
{
    if (frame == NULL)
    {
        return;
    }
    YACSGL_circle_no_offset(frame, x + frame->offset_x, y + frame->offset_y, radius, pixel, YACSGL_CIRCLE_LINE);
    return;
}

int32_t YACSGL_abs(int32_t value)
{
    int32_t ret_val = value;

    if (ret_val < 0)
    {
        ret_val = -ret_val;
    }
    
    return ret_val;
}

/******************** LOCAL FUNCTIONS ****************************************/


static void YACSGL_rect_fill_no_offset(YACSGL_frame_t* frame,
                                       uint16_t x_topleft_width,
                                       uint16_t y_topleft_height,
                                       uint16_t x_bottomright_width,
                                       uint16_t y_bottomright_height,
                                       YACSGL_pixel_t pixel)
{
    /* Check parameters */
    if (x_topleft_width >= frame->frame_x_width)
    {
        return;
    }
    if (y_topleft_height >= frame->frame_y_heigth)
    {
        return;
    }
    if ((x_topleft_width > x_bottomright_width)
        || (y_topleft_height > y_bottomright_height)
        )
    {
        return;
    }

    uint16_t x_final = x_bottomright_width;
    uint16_t y_final = y_bottomright_height;

    if (x_final >= frame->frame_x_width)
    {
        x_final = frame->frame_x_width - 1;
    }
    if (y_final >= frame->frame_y_heigth)
    {
        y_final = frame->frame_y_heigth - 1;
    }

    /* Try to be clever and optimize with memset for aligned area */
    /* Detect first aligned byte */
    uint16_t x_align_start = (x_topleft_width / 8);
    uint16_t x_remaining_before = (x_topleft_width % 8);
    uint8_t unable_to_memset = 0;
    uint16_t size_memset = 0;
    if (x_remaining_before)
    {
        x_align_start++;
    }

    /* Detect last aligned byte and complete */
    uint16_t x_align_end = (x_final / 8);
    uint16_t x_remaining_after = (x_final % 8);
    if (x_remaining_after)
    {
        if (x_align_end == x_align_start)
        {
            /* No memset possible are there is not a complete byte to be set*/
            unable_to_memset = 1;
        }
        else
        {
            x_align_end--;
        }
    }

    /* If a memset can trully occur */
    if (unable_to_memset == 0)
    {
        int32_t delta_y = y_final - y_topleft_height + 1; /* Compute how many line can be memset */
        uint8_t value_to_set = 0;
        if (pixel == YACSGL_P_WHITE)
        {
            value_to_set = 0xFF;
        }
        size_memset = x_align_end - x_align_start + 1;

        for (uint16_t i = 0; i < delta_y; i++)
        {
            memset(&frame->frame_buffer[x_align_start + ((i + y_topleft_height)) * (frame->frame_x_width / 8)],
                value_to_set,
                size_memset);
        }

        /* Complete the missing area of the rectangle with vertical lines */
        uint16_t start_memset_x = x_align_start * 8;
        for (uint16_t i = 0; i < start_memset_x - x_topleft_width; i++)
        {
            YACSGL_line_no_check_no_offset(frame,
                x_topleft_width + i,
                y_topleft_height,
                x_topleft_width + i,
                y_final,
                pixel);
        }
        uint16_t x_end_memset = x_align_end * 8 + 8;
        for (uint16_t i = 0; i <= x_final - x_end_memset; i++)
        {
            YACSGL_line_no_check_no_offset(frame,
                x_end_memset + i,
                y_topleft_height,
                x_end_memset + i,
                y_final, pixel);
        }
    }
    else /* No memset was possible, draw only vertical lines */
    {
        for (uint16_t i = 0; i <= x_final - x_topleft_width; i++)
        {
            YACSGL_line_no_check_no_offset(frame,
                x_topleft_width + i,
                y_topleft_height,
                x_topleft_width + i,
                y_final,
                pixel);
        }
    }

    return;
}

static void YACSGL_rect_line_no_offset(YACSGL_frame_t* frame,
                                       uint16_t x_topleft_width,
                                       uint16_t y_topleft_height,
                                       uint16_t x_bottomright_width,
                                       uint16_t y_bottomright_height,
                                       YACSGL_pixel_t pixel)
{
    /* Check parameters */
    if (x_topleft_width >= frame->frame_x_width)
    {
        return;
    }
    if (y_topleft_height >= frame->frame_y_heigth)
    {
        return;
    }
    if ((x_topleft_width > x_bottomright_width)
        || (y_topleft_height > y_bottomright_height)
        )
    {
        return;
    }

    uint16_t x_final = x_bottomright_width;
    uint16_t y_final = y_bottomright_height;
    uint8_t overshoot_width = 0;
    uint8_t overshoot_heigth = 0;

    if (x_final >= frame->frame_x_width)
    {
        overshoot_width = 1;
        x_final = frame->frame_x_width - 1;
    }
    if (y_final >= frame->frame_y_heigth)
    {
        overshoot_heigth = 1;
        y_final = frame->frame_y_heigth - 1;
    }

    /* Draw the four line of the rectangle */
    /* Top horizontal line */
    YACSGL_line_no_check_no_offset(frame, x_topleft_width, y_topleft_height, x_final, y_topleft_height, pixel);

    if (overshoot_heigth == 0)
    {
        /* Bottom horizontal line */
        YACSGL_line_no_check_no_offset(frame, x_topleft_width, y_final, x_final, y_final, pixel);
    }

    /* Left vertical line */
    YACSGL_line_no_check_no_offset(frame, x_topleft_width, y_topleft_height, x_topleft_width, y_final, pixel);

    if (overshoot_width == 0)
    {
        /* Rigth vertical line */
        YACSGL_line_no_check_no_offset(frame, x_final, y_topleft_height, x_final, y_final, pixel);
    }

    return;
}


static void YACSGL_circle_no_offset(YACSGL_frame_t* frame,
                                    uint16_t x_u, 
                                    uint16_t y_u, 
                                    uint16_t radius_u, 
                                    YACSGL_pixel_t pixel,
                                    YACSGL_circle_type_e type)
{
    int32_t x = x_u; 
    int32_t y = y_u; 
    int32_t radius = radius_u;
    int32_t x_temp = -radius;
    int32_t y_temp = 0;
    int32_t err = 2 - (2 * radius); /* II. Quadrant */ 
    do 
    {
        if (type == YACSGL_CIRCLE_FILL)
        {
            int32_t x_right = x-x_temp;
            int32_t x_left = x+x_temp;

            /* Avoid drawing outside of the frame */
            if (x_left < 0)
            {
                x_left = 0;
            }
            if (x_right >= frame->frame_x_width)
            {
                x_right = frame->frame_x_width - 1;
            }
            
            if (y+y_temp < frame->frame_y_heigth)
            {                
                YACSGL_line_no_offset(frame, x_left, y+y_temp, x_right, y+y_temp, pixel);
            }
            if (y-y_temp >= 0)
            {                
                YACSGL_line_no_offset(frame, x_left, y-y_temp, x_right, y-y_temp, pixel);
            }
        }
        else
        {
            if ((x-x_temp < frame->frame_x_width) && (y+y_temp < frame->frame_y_heigth)) /*   I. Quadrant */
            {
                YACSGL_set_pixel_no_offset(frame, x-x_temp, y+y_temp, pixel); 
            }
            if ((x-y_temp >= 0) && (y-x_temp < frame->frame_y_heigth)) /*  II. Quadrant */
            {
                YACSGL_set_pixel_no_offset(frame, x-y_temp, y-x_temp, pixel); 
            }
            if ((x+x_temp >= 0) && (y-y_temp >= 0)) /* III. Quadrant */
            {
                YACSGL_set_pixel_no_offset(frame, x+x_temp, y-y_temp, pixel); 
            }
            if ((x+y_temp < frame->frame_x_width) && (y+x_temp >= 0)) /*  IV. Quadrant */
            {
                YACSGL_set_pixel_no_offset(frame, x+y_temp, y+x_temp, pixel); 
            }
        }

        radius = err;
        if (radius <= y_temp) 
        {
            err += ++y_temp*2+1; /* e_xy+e_y < 0 */
        }           
        if (radius > x_temp || err > y_temp) 
        {
            err += ++x_temp*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
        }
    } 
    while (x_temp < 0);
    return;
}

static void YACSGL_line_no_offset(YACSGL_frame_t* frame,
                                  uint16_t x0,
                                  uint16_t y0,
                                  uint16_t x1,
                                  uint16_t y1,
                                  YACSGL_pixel_t pixel)
{
    if ((x0 > frame->frame_x_width) || (x1 > frame->frame_x_width))
    {
        return;
    }
    if ((y0 > frame->frame_y_heigth) || (y1 > frame->frame_y_heigth))
    {
        return;
    }
    YACSGL_line_no_check_no_offset(frame, x0, y0, x1, y1, pixel);
}

/** \brief use of Breseham's algorithm */
static void YACSGL_line_no_check_no_offset(YACSGL_frame_t* frame, 
                        uint16_t x0, 
                        uint16_t y0, 
                        uint16_t x1, 
                        uint16_t y1, 
                        YACSGL_pixel_t pixel)
{
    int32_t dx =  YACSGL_abs(x1-x0);
    int32_t sx = (x0<x1 ? 1 : -1);

    int32_t dy = -YACSGL_abs(y1-y0);
    int32_t sy = (y0<y1 ? 1 : -1); 

    int32_t err = dx + dy; /* error value e_xy */
    int32_t e2 = 0; 
 
    for(;;)/* loop */
    {  
        YACSGL_set_pixel_no_offset(frame, x0, y0, pixel);
        /* Evaluate exit condition */
        if (x0==x1 && y0==y1)
        {
            break;
        } 
        e2 = 2*err;
        if (e2 >= dy) /* e_xy+e_x > 0 */
        { 
            err += dy; 
            x0 += sx; 
        } 
        if (e2 <= dx) /* e_xy+e_y < 0 */
        {   err += dx; 
            y0 += sy; 
        } 
    }

    return;
}

/**\} */
/**\} */

/* EOF */
