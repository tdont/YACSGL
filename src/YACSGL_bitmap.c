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
 * \file YAGSGL_bitmap.c
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 12 Dec. 2022
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
#include "YACSGL_bitmap.h"

#include <stddef.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/
static void YACSGL_bitmap_disp_slow(YACSGL_frame_t* frame,
    uint16_t x_width,
    uint16_t y_height,
    YACSGL_pixel_t pixel,
    const YACSGL_bitmap_t* const bitmap);

/******************** API FUNCTIONS ******************************************/
void YACSGL_bitmap_disp(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel,
                        const YACSGL_bitmap_t* const bitmap)
{
    /* Check parameters */
    if (frame == NULL)
    {
        return;
    }
    if (bitmap == NULL)
    {
        return;
    }

    YACSGL_bitmap_disp_slow(frame,
        x_width ,
        y_height,
        pixel,
        bitmap);

    //uint8_t offset_first_byte = x_width % 8;
    //uint16_t index_frame = 0;

    ///* Display Bitmap */
    //for(uint16_t y_bmp = 0; y_bmp < bitmap->height; y_bmp++)
    //{
    //    index_frame = (y_bmp * (frame->frame_x_width / 8));
    //    /* if width is not aligned with a byte */
    //    if(offset_first_byte != 0)
    //    {
    //        uint8_t first_byte = (0xFF << (8 - (8 - offset_first_byte)) | (bitmap->bitmap_buffer[y_bmp * nb_byte_per_line] >> offset_first_byte));
    //        frame->frame_buffer[index_frame] &= ~first_byte;
    //        frame->frame_buffer[index_frame] |= first_byte;
    //    }

    //    for(uint16_t x_bmp = 0; x_bmp < bitmap->width; x_bmp+=8)
    //    {
    //        if(offset_first_byte != 0)
    //        {
    //            /* TODO handle the recomposition of byte here */
    //        }
    //        else
    //        {
    //            frame->frame_buffer[index_frame + x_bmp / 8] = bitmap->bitmap_buffer[y_bmp * nb_byte_per_line + x_bmp / 8];
    //        }
    //    }

    //    /* TODO handle the remaining pixel of bitmatp */

    //}
   

}

/******************** LOCAL FUNCTIONS ****************************************/
static void YACSGL_bitmap_disp_slow(YACSGL_frame_t* frame,
    uint16_t x_width,
    uint16_t y_height,
    YACSGL_pixel_t pixel,
    const YACSGL_bitmap_t* const bitmap)
{
    /* Ensure the drawing will stay in the buffer (TODO improve to be able to partially draw) */
    if ((x_width + frame->offset_x + bitmap->width >= frame->frame_x_width)
        || (y_height + frame->offset_y + bitmap->height >= frame->frame_y_heigth)
        )
    {
        return;
    }

    /* Compute number of byte per line */
    uint16_t nb_byte_per_line = bitmap->width / 8 + ((bitmap->width % 8) ? 1 : 0);

    /* For each line in bitmap */
    for (uint16_t bitmap_y = 0; bitmap_y++; bitmap_y < bitmap->height)
    {
        /* For each byte in line */
        for (uint16_t byte_in_line_x = 0; byte_in_line_x++; byte_in_line_x < nb_byte_per_line)
        {
            uint8_t current_byte = bitmap->bitmap_buffer[(bitmap_y * nb_byte_per_line) + byte_in_line_x];
            /* For each bit in byte */
            for (uint8_t current_pixel = 0; current_pixel++; current_pixel < 8)
            {
                /* Only draw if pixel is set to one (allow r*/
                if (current_byte & (0b1 << 7 - current_pixel))
                {
                    YACSGL_set_pixel(frame,
                        x_width + byte_in_line_x * 8 + current_pixel,
                        y_height + bitmap_y,
                        pixel);
                }

            }
        }
    }



    return;
}

/**\} */
/**\} */

/* EOF */

	
	
	
