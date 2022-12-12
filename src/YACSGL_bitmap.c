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
    if (    (x_width + bitmap->width >= frame->frame_x_width)
        ||  (y_height + bitmap->height >= frame->frame_y_heigth)
       )
    {
        return;
    }

    /* Display Bitmap */
    // for(uint16_t y_char = 0; y_char < font->height; y_char++)
    // {
    //     /* TODO handle the case where the block size is two bytes and not only one ! */
    //     uint8_t current_val = font->table[((char_to_draw - font->first_char) * font->height) + y_char];
    //     for(uint16_t x_char = 0; x_char < font->width; x_char++)
    //     {
    //         /* Display pixel by pixel the font (TODO improve) */
    //         if((current_val & (0b1 << (7 - x_char))) != 0)
    //         {
    //             YACSGL_set_pixel(frame, x_width + x_char, y_height + y_char, pixel);
    //         }
    //     }
    // }
   

}

/******************** LOCAL FUNCTIONS ****************************************/


/**\} */
/**\} */

/* EOF */

	
	
	
