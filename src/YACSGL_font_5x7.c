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
 * \file YAGSGL_font_5x7.c
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
#include <stdint.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/
uint8_t table[] = { 10, 20 }; /* TODO dummy table to be filled ... by hand for now :( */

YACSGL_font_t YACSGL_font_5x7 = {
                                    7, /* Height */
                                    5, /* Width */
                                    1, /* One byte per line */
                                    0x21, /* First character of the table */
                                    0x7E, /* Last character of the table */
                                    table /* Font table */
};

/******************** LOCAL FUNCTION PROTOTYPE *******************************/

/******************** API FUNCTIONS ******************************************/

/******************** LOCAL FUNCTIONS ****************************************/


/**\} */
/**\} */

/* EOF */
