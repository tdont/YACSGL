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
 * \date 12 Aug. 2022
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
#ifndef INC_YACSGL_H_
#define INC_YACSGL_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdint.h>

#include "YACSGL_pixel.h"


/******************** CONSTANTS OF MODULE ************************************/
#define YACSGL_BUFFER_SIZE_COMPUTE(width, height)     (width * height / 8)

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef struct 
{
    uint16_t frame_x_width;  /* must be a multiple of 8 */
    uint16_t frame_y_heigth;
    uint16_t offset_x;
    uint16_t offset_y;
    uint8_t* frame_buffer;
}YACSGL_frame_t;

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE ************ ********************/
/** \brief Set a pixel to the value given to the pen 
 * /!\ For speed reason, this function has no check, make sure you are drawing inside the frame
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x_width   Coordonate in the abscyss axe
 * \param y_height  Coordonaite in the ordonnate axe
 * \param pixel       Pixel color to be applied
 */
void YACSGL_set_pixel(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel);

/** \brief Draw a filled rectangle with the pixel color 
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x_topleft_width   Coordonate in the abscyss axe of the top left corner 
 * \param y_topleft_height  Coordonaite in the ordonnate axe of the top left corner
 * \param x_bottomright_width Coordonate in the abscyss axe of the bottom right corner 
 * \param y_bottomright_height Coordonate in the ordonnate axe of the bottom right corner 
 * \param pixel       Pixel color to be applied
 */
void YACSGL_rect_fill(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel);

/** \brief Draw a the external lines of a  rectangle and leave the inside untouched  
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x_topleft_width   Coordonate in the abscyss axe of the top left corner 
 * \param y_topleft_height  Coordonaite in the ordonnate axe of the top left corner
 * \param x_bottomright_width Coordonate in the abscyss axe of the bottom right corner 
 * \param y_bottomright_height Coordonate in the ordonnate axe of the bottom right corner 
 * \param pixel       Pixel color to be applied
 */
void YACSGL_rect_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel);   

/** \brief Draw a line between two dot 
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x0        Coordonate in the abscyss axe of the first dot 
 * \param y0        Coordonaite in the ordonnate axe of the first dot
 * \param x1        Coordonate in the abscyss axe of the second dot 
 * \param y1        Coordonate in the ordonnate axe of the second dot 
 * \param pixel     Pixel color to be applied
 */
void YACSGL_line(YACSGL_frame_t* frame, 
                        uint16_t x0, 
                        uint16_t y0, 
                        uint16_t x1, 
                        uint16_t y1, 
                        YACSGL_pixel_t pixel);      

/** \brief Draw a filled circle (or disc) with the pixel color 
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x         Coordonate in the abscyss axe of center
 * \param y         Coordonaite in the ordonnate axe of the center
 * \param radius    Radius in pixel 
 * \param pixel     Pixel color to be applied
 */
void YACSGL_circle_fill(YACSGL_frame_t* frame, 
                        uint16_t x, 
                        uint16_t y, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel);   

/** \brief Draw a circle with the pixel color and leave the inside untouched  
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x         Coordonate in the abscyss axe of center
 * \param y         Coordonaite in the ordonnate axe of the center
 * \param radius    Radius in pixel 
 * \param pixel     Pixel color to be applied
 */
void YACSGL_circle_line(YACSGL_frame_t* frame, 
                        uint16_t x, 
                        uint16_t y, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel); 

/** \brief Compute the absolute value of a given value (avoid stdlib)
 * 
 * \param value     Value we want to get absolute value 
 * 
 * \return          The absolute value
 */
int32_t YACSGL_abs(int32_t value);

#ifdef __cplusplus
}
#endif


#endif /* INC_YACSGL_H_ */

/**\} */
/**\} */

/* EOF */
