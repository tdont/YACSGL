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
 * \file YAGSGL_font.h
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 20 Aug. 2022
 */

/**
 * \cond EXTERNAL_DOC
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

/* Prevent multiple inclusions */
#ifndef INC_YACSGL_FONT_H_
#define INC_YACSGL_FONT_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdbool.h>
#include <stdint.h>
#include "YACSGL.h"
#include "YACSGL_pixel.h"

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef enum
{
    YACSGL_NEWLINE_DISABLED = 0,
    YACSGL_NEWLINE_ENABLED
}YACSGL_txt_newline_mode_e;

typedef struct
{
    uint8_t height;
    uint8_t width;
    uint8_t nb_byte_line;
    char    first_char;
    char    last_char;
    char    not_found_joker;
    uint8_t* table;
}YACSGL_font_t;

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE *********************************/
/** \brief Display a text at the coordonates (only if it stays in the frame) 
 *  Can go to the line is indicated as such and a newline character (\r or \n) is present) 
 * 
 * \param frame         Frame where the paiting shall be done
 * \param x_width       Coordonate in the abscyss axe
 * \param y_height      Coordonaite in the ordonnate axe
 * \param pixel         Pixel color to be applied
 * \param font          Font that will be applied to display the text
 * \param text          Text to be displayed on the frame
 * \param newline_mode  Indicate if newline shall be detected and accounted for it 
 *                      If newline mode is disabled, a newline is considered as an end of string
*/
void YACSGL_font_txt_disp(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel,
                        const YACSGL_font_t* const font,
                        const char* const text,
                        YACSGL_txt_newline_mode_e newline_mode);

#ifdef __cplusplus
}
#endif

#endif /* INC_YACSGL_FONT_H_ */

/**\} */
/**\} */

/* EOF */