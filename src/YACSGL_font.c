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
 * \file YAGSGL_font.c
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 21 Aug. 2022
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
#include "YACSGL_font.h"
#include "YACSGL.h"

/******************** CONSTANTS OF MODULE ************************************/
#define YACSGL_FONT_MISSING_CHAR    ' '

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/

/******************** API FUNCTIONS ******************************************/
void YACSGL_font_txt_disp(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel,
                        const YACSGL_font_t* const font,
                        const char* const text,
                        YACSGL_txt_newline_mode_e newline_mode)
{
    /* Check parameters */
    if (frame == NULL)
    {
        return;
    }
    if (font == NULL)
    {
        return;
    }
    if (text == NULL)
    {
        return;
    }
    if (    (x_width + font->width >= frame->frame_x_width)
        ||  (y_height + font->height >= frame->frame_y_heigth)
       )
    {
        return;
    }
    if(text[0] == 0)
    {
        return;
    }
    if(    (newline_mode == YACSGL_NEWLINE_DISABLED) 
        && ((text[0] == '\r') || (text[0] == '\n'))
      )
    {
        return;
    }

    uint32_t current_line = 0;
    uint16_t x_offset = 0;
    uint16_t y_offset = 0;
    uint8_t stop = 0;

    uint16_t current_char = 0;

    do
    {
        /* TODO Draw char */
        /* For now just draw a line (temporary) */
        YACSGL_line(frame, x_width + x_offset, y_height + y_offset, x_width + x_offset + font->width, y_height + y_offset, YACSGL_P_WHITE);


        /* Increment current char */
        current_char++;
        x_offset += font->width;

        /* Check newline condition */  
        if(text[current_char] == '\r' || text[current_char] == '\n')
        {
            if(newline_mode == YACSGL_NEWLINE_DISABLED)
            {
                /* Stop the displaying of font */
                stop = 1;
            }
            else
            {
                /* New line */
                x_offset = 0;
                y_offset += font->height;
            }
        }      

        /* Check stop condition (end of string) */
        if(text[current_char] == 0)
        {
            stop = 1;
        }

        /* Check stop condition (unable to draw a new char) */
        if (        (x_width + x_offset + font->width >= frame->frame_x_width)
                ||  (y_height + y_offset + font->height >= frame->frame_y_heigth)
            )
        {
            stop = 1;;
        }

    }while(stop == 0);
    


    return;
}

/******************** LOCAL FUNCTIONS ****************************************/


/**\} */
/**\} */

/* EOF */

	
	
	
