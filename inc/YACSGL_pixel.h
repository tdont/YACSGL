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