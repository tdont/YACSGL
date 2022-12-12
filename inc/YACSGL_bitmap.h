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
 * \file YAGSGL.h
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 12 Dec. 2022
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
#ifndef INC_YACSGL_BITMAP_H_
#define INC_YACSGL_BITMAP_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdint.h>

#include "YACSGL.h"


/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef struct
{
    uint8_t height;
    uint8_t width;
    uint8_t nb_byte_line;
    uint8_t* bitmap_buffer;
}YACSGL_bitmap_t;

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE *********************************/
/** \brief Display a bitmap at the coordonates (only if it stays in the frame) 
 * 
 * \param frame         Frame where the paiting shall be done
 * \param x_width       Coordonate in the abscyss axe
 * \param y_height      Coordonaite in the ordonnate axe
 * \param pixel         Pixel color to be applied
 * \param bitmap        Bitmap that will be applied to display the text
*/
void YACSGL_bitmap_disp(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel,
                        const YACSGL_bitmap_t* const bitmap);


#ifdef __cplusplus
}
#endif


#endif /* INC_YACSGL_BITMAP_H_ */

/**\} */
/**\} */

/* EOF */
