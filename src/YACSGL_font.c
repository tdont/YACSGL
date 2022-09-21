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
static void YACSGL_font_draw_char(YACSGL_frame_t* frame, 
                                    uint16_t x_width, 
                                    uint16_t y_height, 
                                    YACSGL_pixel_t pixel,
                                    const YACSGL_font_t* const font,
                                    char character);

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
        switch (text[current_char])
		{
			case '\r':
			case '\n':
				/* Check newline condition */
				if (newline_mode == YACSGL_NEWLINE_DISABLED)
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
				break;
			case ' ': /* Check space condition */
				/* Add a space without drawing */
				x_offset += font->width;
				break;
			case 0: /* End of line, stop */
				stop = 1;
				break;
			default:
				/* Draw char */
				YACSGL_font_draw_char(frame, x_width + x_offset, y_height + y_offset, pixel, font, text[current_char]);
				x_offset += font->width;
				break;
		}

        /* Increment current char */
        current_char++;

        /* Check stop condition (unable to draw a new char inside the frame) */
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
static void YACSGL_font_draw_char(YACSGL_frame_t* frame, 
                                    uint16_t x_width, 
                                    uint16_t y_height, 
                                    YACSGL_pixel_t pixel,
                                    const YACSGL_font_t* const font,
                                    char character)
{
    /* Check parameters */
    char char_to_draw = character;

    if((character < font->first_char) || (character > font->last_char))
    {
        char_to_draw = font->not_found_joker;
    }

    for(uint16_t y_char = 0; y_char < font->height; y_char++)
    {
        /* TODO handle the case where the block size is two bytes and not only one ! */
        uint8_t current_val = font->table[((char_to_draw - font->first_char) * font->height) + y_char];
        for(uint16_t x_char = 0; x_char < font->width; x_char++)
        {
            /* Display pixel by pixel the font (TODO improve) */
            if((current_val & (0b1 << (7 - x_char))) != 0)
            {
                YACSGL_set_pixel(frame, x_width + x_char, y_height + y_char, pixel);
            }
        }
    }
}

/**\} */
/**\} */

/* EOF */

	
	
	
