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
#ifndef INC_YACSGL_PIXEL_H_
#define INC_YACSGL_PIXEL_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdbool.h>
#include <stdint.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef enum{
    YACSGL_P_BLACK = 0,
    YACSGL_P_WHITE = 1
}YACSGL_pixel_t;
/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE *********************************/
#ifdef __cplusplus
}
#endif

#endif /* INC_TEMPLATE_H_ */

/**\} */
/**\} */

/* EOF */