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
static void YACSGL_circle(YACSGL_frame_t* frame, 
                        uint16_t x_u, 
                        uint16_t y_u, 
                        uint16_t radius_u, 
                        YACSGL_pixel_t pixel,
                        YACSGL_circle_type_e type);

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
        else
        {            
            x_align_end--;
        }
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

		/* Complete the missing area of the rectangle with vertical lines */
		uint16_t start_memset_x = x_align_start * 8;
		for (uint16_t i = 0; i < start_memset_x - x_topleft_width; i++)
		{
			YACSGL_line(frame, x_topleft_width + i, y_topleft_height, x_topleft_width + i, y_bottomright_height, pixel);
		}
		uint16_t x_end_memset = x_align_end * 8 + 8;
		for (uint16_t i = 0; i <= x_bottomright_width - x_end_memset; i++)
		{
			YACSGL_line(frame,
				x_end_memset + i,
				y_topleft_height,
				x_end_memset + i,
				y_bottomright_height, pixel);
		}
    }
	else /* No memset was possible, draw only vertical lines */
	{
		for (uint16_t i = 0; i <= x_bottomright_width - x_topleft_width; i++)
		{
			YACSGL_line(frame, x_topleft_width + i, y_topleft_height, x_topleft_width + i, y_bottomright_height, pixel);
		}
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

/** \brief use of Breseham's algorithm */
void YACSGL_line(YACSGL_frame_t* frame, 
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
        YACSGL_set_pixel(frame, x0, y0, pixel);
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

void YACSGL_circle_fill(YACSGL_frame_t* frame, 
                        uint16_t x, 
                        uint16_t y, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel)
{
    YACSGL_circle(frame, x, y, radius, pixel, YACSGL_CIRCLE_FILL);
    return;
}

/** \brief use of Breseham's algorithm */
void YACSGL_circle_line(YACSGL_frame_t* frame, 
                        uint16_t x, 
                        uint16_t y, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel)   
{
    YACSGL_circle(frame, x, y, radius, pixel, YACSGL_CIRCLE_LINE);
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
static void YACSGL_circle(YACSGL_frame_t* frame, 
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
            YACSGL_line(frame, x-x_temp, y+y_temp, x+x_temp, y+y_temp, pixel);
            YACSGL_line(frame, x-x_temp, y-y_temp, x+x_temp, y-y_temp, pixel);
        }
        else
        {
            YACSGL_set_pixel(frame, x-x_temp, y+y_temp, pixel); /*   I. Quadrant */
            YACSGL_set_pixel(frame, x-y_temp, y-x_temp, pixel); /*  II. Quadrant */
            YACSGL_set_pixel(frame, x+x_temp, y-y_temp, pixel); /* III. Quadrant */
            YACSGL_set_pixel(frame, x+y_temp, y+x_temp, pixel); /*  IV. Quadrant */
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

/**\} */
/**\} */

/* EOF */
