/******************************************************************************
 * COPYRIGHT (C) Guerwood 2022. All rights reserved.
 *****************************************************************************/

/******************** FILE HEADER ********************************************/
/**\addtogroup ModuleName_External_Documentation
 * \{ */
/**\addtogroup SubModuleName
 * \{ */

/**
 * \file YAGSGL_pixel.h
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

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef struct 
{
    uint16_t frame_x_width;  /* must be a multiple of 8 */
    uint16_t frame_y_heigth;
    uint8_t* frame_buffer;
}YACSGL_frame_t;

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE ************ ********************/
/** \brief Set a pixel to the value given to the pen 
 * 
 * \param frame     Frame where the paiting shall be done
 * \param x_width   Coordonate in the abscyss axe
 * \param y_height  Coordonaite in the ordonnate axe
 * \param pen       Pixel color to be applied
 */
void YACSGL_set_pixel(YACSGL_frame_t* frame, 
                        uint16_t x_width, 
                        uint16_t y_height, 
                        YACSGL_pixel_t pixel);

void YACSGL_rect_fill(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel);

void YACSGL_rect_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel);   

void YACSGL_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t x_bottomright_width, 
                        uint16_t y_bottomright_height, 
                        YACSGL_pixel_t pixel);      

void YACSGL_circle_fill(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel);   

void YACSGL_circle_line(YACSGL_frame_t* frame, 
                        uint16_t x_topleft_width, 
                        uint16_t y_topleft_height, 
                        uint16_t radius, 
                        YACSGL_pixel_t pixel);                                  

#ifdef __cplusplus
}
#endif


#endif /* INC_TEMPLATE_H_ */

/**\} */
/**\} */

/* EOF */