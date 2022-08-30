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
uint8_t table[] = {

	/* Character (0x21):
	 +----------------+
	 |  *             |
	 |  *             |
	 |  *             |
	 |  *             |
	 |                |
	 |  *             |
	 |                |
	 +----------------+ */
	0x20,
	0x20,
	0x20,
	0x20,
	0x00,
	0x20,
	0x00,

	/* Character (0x22):
	 +----------------+
	 | * *            |
	 | * *            |
	 | * *            |
	 |                |
	 |                |
	 |                |
	 |                |
	 +----------------+ */
	0x50,
	0x50,
	0x50,
	0x00,
	0x00,
	0x00,
	0x00,

	/* Character (0x23):
	 +----------------+
	 |                |
	 | * *            |
	 |*****           |
	 | * *            |
	 |*****           |
	 | * *            |
	 |                |
	 +----------------+ */
	0x00,
	0x50,
	0xf8,
	0x50,
	0xf8,
	0x50,
	0x00,

	/* Character (0x24):
	 +----------------+
	 |                |
	 | ***            |
	 |* *             |
	 | ***            |
	 |  * *           |
	 | ***            |
	 |                |
	 +----------------+ */
	0x00,
	0x70,
	0xa0,
	0x70,
	0x28,
	0x70,
	0x00,

	/* Character (0x25):
	 +----------------+
	 |*               |
	 |*  *            |
	 |  *             |
	 | *              |
	 |*  *            |
	 |   *            |
	 |                |
	 +----------------+ */
	0x80,
	0x90,
	0x20,
	0x40,
	0x90,
	0x10,
	0x00,

	/* Character (0x26):
	 +----------------+
	 |                |
	 | *              |
	 |* *             |
	 | *              |
	 |* *             |
	 | * *            |
	 |                |
	 +----------------+ */
	0x00,
	0x40,
	0xa0,
	0x40,
	0xa0,
	0x50,
	0x00,

	/* Character (0x27):
	 +----------------+
	 | **             |
	 | *              |
	 |*               |
	 |                |
	 |                |
	 |                |
	 |                |
	 +----------------+ */
	0x60,
	0x40,
	0x80,
	0x00,
	0x00,
	0x00,
	0x00,

	/* Character (0x28):
	 +----------------+
	 |  *             |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 |  *             |
	 |                |
	 +----------------+ */
	0x20,
	0x40,
	0x40,
	0x40,
	0x40,
	0x20,
	0x00,

	/* Character (0x29):
	 +----------------+
	 | *              |
	 |  *             |
	 |  *             |
	 |  *             |
	 |  *             |
	 | *              |
	 |                |
	 +----------------+ */
	0x40,
	0x20,
	0x20,
	0x20,
	0x20,
	0x40,
	0x00,

	/* Character (0x2a):
	 +----------------+
	 |                |
	 |* *             |
	 | *              |
	 |***             |
	 | *              |
	 |* *             |
	 |                |
	 +----------------+ */
	0x00,
	0xa0,
	0x40,
	0xe0,
	0x40,
	0xa0,
	0x00,

	/* Character (0x2b):
	 +----------------+
	 |                |
	 |  *             |
	 |  *             |
	 |*****           |
	 |  *             |
	 |  *             |
	 |                |
	 +----------------+ */
	0x00,
	0x20,
	0x20,
	0xf8,
	0x20,
	0x20,
	0x00,

	/* Character (0x2c):
	 +----------------+
	 |                |
	 |                |
	 |                |
	 |                |
	 | **             |
	 | *              |
	 |*               |
	 +----------------+ */
	0x00,
	0x00,
	0x00,
	0x00,
	0x60,
	0x40,
	0x80,

	/* Character (0x2d):
	 +----------------+
	 |                |
	 |                |
	 |                |
	 |****            |
	 |                |
	 |                |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x00,
	0xf0,
	0x00,
	0x00,
	0x00,

	/* Character (0x2e):
	 +----------------+
	 |                |
	 |                |
	 |                |
	 |                |
	 | **             |
	 | **             |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x00,
	0x00,
	0x60,
	0x60,
	0x00,

	/* Character (0x2f):
	 +----------------+
	 |                |
	 |   *            |
	 |  *             |
	 | *              |
	 |*               |
	 |                |
	 |                |
	 +----------------+ */
	0x00,
	0x10,
	0x20,
	0x40,
	0x80,
	0x00,
	0x00,

	/* Character (0x30):
	 +----------------+
	 | *              |
	 |* *             |
	 |* *             |
	 |* *             |
	 |* *             |
	 | *              |
	 |                |
	 +----------------+ */
	0x40,
	0xa0,
	0xa0,
	0xa0,
	0xa0,
	0x40,
	0x00,

	/* Character (0x31):
	 +----------------+
	 | *              |
	 |**              |
	 | *              |
	 | *              |
	 | *              |
	 |***             |
	 |                |
	 +----------------+ */
	0x40,
	0xc0,
	0x40,
	0x40,
	0x40,
	0xe0,
	0x00,

	/* Character (0x32):
	 +----------------+
	 | **             |
	 |*  *            |
	 |   *            |
	 |  *             |
	 | *              |
	 |****            |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x10,
	0x20,
	0x40,
	0xf0,
	0x00,

	/* Character (0x33):
	 +----------------+
	 |****            |
	 |   *            |
	 | **             |
	 |   *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0xf0,
	0x10,
	0x60,
	0x10,
	0x90,
	0x60,
	0x00,

	/* Character (0x34):
	 +----------------+
	 |  *             |
	 | **             |
	 |* *             |
	 |****            |
	 |  *             |
	 |  *             |
	 |                |
	 +----------------+ */
	0x20,
	0x60,
	0xa0,
	0xf0,
	0x20,
	0x20,
	0x00,

	/* Character (0x35):
	 +----------------+
	 |****            |
	 |*               |
	 |***             |
	 |   *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0xf0,
	0x80,
	0xe0,
	0x10,
	0x90,
	0x60,
	0x00,

	/* Character (0x36):
	 +----------------+
	 | **             |
	 |*               |
	 |***             |
	 |*  *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x80,
	0xe0,
	0x90,
	0x90,
	0x60,
	0x00,

	/* Character (0x37):
	 +----------------+
	 |****            |
	 |   *            |
	 |  *             |
	 |  *             |
	 | *              |
	 | *              |
	 |                |
	 +----------------+ */
	0xf0,
	0x10,
	0x20,
	0x20,
	0x40,
	0x40,
	0x00,

	/* Character (0x38):
	 +----------------+
	 | **             |
	 |*  *            |
	 | **             |
	 |*  *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x60,
	0x90,
	0x90,
	0x60,
	0x00,

	/* Character (0x39):
	 +----------------+
	 | **             |
	 |*  *            |
	 |*  *            |
	 | ***            |
	 |   *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x90,
	0x70,
	0x10,
	0x60,
	0x00,

	/* Character (0x3a):
	 +----------------+
	 |                |
	 | **             |
	 | **             |
	 |                |
	 | **             |
	 | **             |
	 |                |
	 +----------------+ */
	0x00,
	0x60,
	0x60,
	0x00,
	0x60,
	0x60,
	0x00,

	/* Character (0x3b):
	 +----------------+
	 |                |
	 | **             |
	 | **             |
	 |                |
	 | **             |
	 | *              |
	 |*               |
	 +----------------+ */
	0x00,
	0x60,
	0x60,
	0x00,
	0x60,
	0x40,
	0x80,

	/* Character (0x3c):
	 +----------------+
	 |                |
	 |  *             |
	 | *              |
	 |*               |
	 | *              |
	 |  *             |
	 |                |
	 +----------------+ */
	0x00,
	0x20,
	0x40,
	0x80,
	0x40,
	0x20,
	0x00,

	/* Character (0x3d):
	 +----------------+
	 |                |
	 |                |
	 |****            |
	 |                |
	 |****            |
	 |                |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0xf0,
	0x00,
	0xf0,
	0x00,
	0x00,

	/* Character (0x3e):
	 +----------------+
	 |                |
	 |*               |
	 | *              |
	 |  *             |
	 | *              |
	 |*               |
	 |                |
	 +----------------+ */
	0x00,
	0x80,
	0x40,
	0x20,
	0x40,
	0x80,
	0x00,

	/* Character (0x3f):
	 +----------------+
	 | *              |
	 |* *             |
	 |  *             |
	 | *              |
	 |                |
	 | *              |
	 |                |
	 +----------------+ */
	0x40,
	0xa0,
	0x20,
	0x40,
	0x00,
	0x40,
	0x00,

	/* Character (0x40):
	 +----------------+
	 | **             |
	 |*  *            |
	 |* **            |
	 |* **            |
	 |*               |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0xb0,
	0xb0,
	0x80,
	0x60,
	0x00,

	/* Character (0x41):
	 +----------------+
	 | **             |
	 |*  *            |
	 |*  *            |
	 |****            |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x90,
	0xf0,
	0x90,
	0x90,
	0x00,

	/* Character (0x42):
	 +----------------+
	 |***             |
	 |*  *            |
	 |***             |
	 |*  *            |
	 |*  *            |
	 |***             |
	 |                |
	 +----------------+ */
	0xe0,
	0x90,
	0xe0,
	0x90,
	0x90,
	0xe0,
	0x00,

	/* Character (0x43):
	 +----------------+
	 | **             |
	 |*  *            |
	 |*               |
	 |*               |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x80,
	0x80,
	0x90,
	0x60,
	0x00,

	/* Character (0x44):
	 +----------------+
	 |***             |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |***             |
	 |                |
	 +----------------+ */
	0xe0,
	0x90,
	0x90,
	0x90,
	0x90,
	0xe0,
	0x00,

	/* Character (0x45):
	 +----------------+
	 |****            |
	 |*               |
	 |***             |
	 |*               |
	 |*               |
	 |****            |
	 |                |
	 +----------------+ */
	0xf0,
	0x80,
	0xe0,
	0x80,
	0x80,
	0xf0,
	0x00,

	/* Character (0x46):
	 +----------------+
	 |****            |
	 |*               |
	 |***             |
	 |*               |
	 |*               |
	 |*               |
	 |                |
	 +----------------+ */
	0xf0,
	0x80,
	0xe0,
	0x80,
	0x80,
	0x80,
	0x00,

	/* Character (0x47):
	 +----------------+
	 | **             |
	 |*  *            |
	 |*               |
	 |* **            |
	 |*  *            |
	 | ***            |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x80,
	0xb0,
	0x90,
	0x70,
	0x00,

	/* Character (0x48):
	 +----------------+
	 |*  *            |
	 |*  *            |
	 |****            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x90,
	0x90,
	0xf0,
	0x90,
	0x90,
	0x90,
	0x00,

	/* Character (0x49):
	 +----------------+
	 |***             |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 |***             |
	 |                |
	 +----------------+ */
	0xe0,
	0x40,
	0x40,
	0x40,
	0x40,
	0xe0,
	0x00,

	/* Character (0x4a):
	 +----------------+
	 |   *            |
	 |   *            |
	 |   *            |
	 |   *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x10,
	0x10,
	0x10,
	0x10,
	0x90,
	0x60,
	0x00,

	/* Character (0x4b):
	 +----------------+
	 |*  *            |
	 |* *             |
	 |**              |
	 |**              |
	 |* *             |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x90,
	0xa0,
	0xc0,
	0xc0,
	0xa0,
	0x90,
	0x00,

	/* Character (0x4c):
	 +----------------+
	 |*               |
	 |*               |
	 |*               |
	 |*               |
	 |*               |
	 |****            |
	 |                |
	 +----------------+ */
	0x80,
	0x80,
	0x80,
	0x80,
	0x80,
	0xf0,
	0x00,

	/* Character (0x4d):
	 +----------------+
	 |*  *            |
	 |****            |
	 |****            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x90,
	0xf0,
	0xf0,
	0x90,
	0x90,
	0x90,
	0x00,

	/* Character (0x4e):
	 +----------------+
	 |*  *            |
	 |** *            |
	 |** *            |
	 |* **            |
	 |* **            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x90,
	0xd0,
	0xd0,
	0xb0,
	0xb0,
	0x90,
	0x00,

	/* Character (0x4f):
	 +----------------+
	 | **             |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x90,
	0x90,
	0x90,
	0x60,
	0x00,

	/* Character (0x50):
	 +----------------+
	 |***             |
	 |*  *            |
	 |*  *            |
	 |***             |
	 |*               |
	 |*               |
	 |                |
	 +----------------+ */
	0xe0,
	0x90,
	0x90,
	0xe0,
	0x80,
	0x80,
	0x00,

	/* Character (0x51):
	 +----------------+
	 | **             |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |** *            |
	 | **             |
	 |   *            |
	 +----------------+ */
	0x60,
	0x90,
	0x90,
	0x90,
	0xd0,
	0x60,
	0x10,

	/* Character (0x52):
	 +----------------+
	 |***             |
	 |*  *            |
	 |*  *            |
	 |***             |
	 |* *             |
	 |*  *            |
	 |                |
	 +----------------+ */
	0xe0,
	0x90,
	0x90,
	0xe0,
	0xa0,
	0x90,
	0x00,

	/* Character (0x53):
	 +----------------+
	 | **             |
	 |*  *            |
	 | *              |
	 |  *             |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x60,
	0x90,
	0x40,
	0x20,
	0x90,
	0x60,
	0x00,

	/* Character (0x54):
	 +----------------+
	 |***             |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 |                |
	 +----------------+ */
	0xe0,
	0x40,
	0x40,
	0x40,
	0x40,
	0x40,
	0x00,

	/* Character (0x55):
	 +----------------+
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x90,
	0x90,
	0x90,
	0x90,
	0x90,
	0x60,
	0x00,

	/* Character (0x56):
	 +----------------+
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 | **             |
	 | **             |
	 |                |
	 +----------------+ */
	0x90,
	0x90,
	0x90,
	0x90,
	0x60,
	0x60,
	0x00,

	/* Character (0x57):
	 +----------------+
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |****            |
	 |****            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x90,
	0x90,
	0x90,
	0xf0,
	0xf0,
	0x90,
	0x00,

	/* Character (0x58):
	 +----------------+
	 |*  *            |
	 |*  *            |
	 | **             |
	 | **             |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x90,
	0x90,
	0x60,
	0x60,
	0x90,
	0x90,
	0x00,

	/* Character (0x59):
	 +----------------+
	 |* *             |
	 |* *             |
	 |* *             |
	 | *              |
	 | *              |
	 | *              |
	 |                |
	 +----------------+ */
	0xa0,
	0xa0,
	0xa0,
	0x40,
	0x40,
	0x40,
	0x00,

	/* Character (0x5a):
	 +----------------+
	 |****            |
	 |   *            |
	 |  *             |
	 | *              |
	 |*               |
	 |****            |
	 |                |
	 +----------------+ */
	0xf0,
	0x10,
	0x20,
	0x40,
	0x80,
	0xf0,
	0x00,

	/* Character (0x5b):
	 +----------------+
	 |***             |
	 |*               |
	 |*               |
	 |*               |
	 |*               |
	 |***             |
	 |                |
	 +----------------+ */
	0xe0,
	0x80,
	0x80,
	0x80,
	0x80,
	0xe0,
	0x00,

	/* Character (0x5c):
	 +----------------+
	 |                |
	 |*               |
	 | *              |
	 |  *             |
	 |   *            |
	 |                |
	 |                |
	 +----------------+ */
	0x00,
	0x80,
	0x40,
	0x20,
	0x10,
	0x00,
	0x00,

	/* Character (0x5d):
	 +----------------+
	 |***             |
	 |  *             |
	 |  *             |
	 |  *             |
	 |  *             |
	 |***             |
	 |                |
	 +----------------+ */
	0xe0,
	0x20,
	0x20,
	0x20,
	0x20,
	0xe0,
	0x00,

	/* Character (0x5e):
	 +----------------+
	 | *              |
	 |* *             |
	 |                |
	 |                |
	 |                |
	 |                |
	 |                |
	 +----------------+ */
	0x40,
	0xa0,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,

	/* Character (0x5f):
	 +----------------+
	 |                |
	 |                |
	 |                |
	 |                |
	 |                |
	 |****            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0xf0,
	0x00,

	/* Character (0x60):
	 +----------------+
	 |**              |
	 | *              |
	 |  *             |
	 |                |
	 |                |
	 |                |
	 |                |
	 +----------------+ */
	0xc0,
	0x40,
	0x20,
	0x00,
	0x00,
	0x00,
	0x00,

	/* Character (0x61):
	 +----------------+
	 |                |
	 |                |
	 | ***            |
	 |*  *            |
	 |* **            |
	 | * *            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x70,
	0x90,
	0xb0,
	0x50,
	0x00,

	/* Character (0x62):
	 +----------------+
	 |*               |
	 |*               |
	 |***             |
	 |*  *            |
	 |*  *            |
	 |***             |
	 |                |
	 +----------------+ */
	0x80,
	0x80,
	0xe0,
	0x90,
	0x90,
	0xe0,
	0x00,

	/* Character (0x63):
	 +----------------+
	 |                |
	 |                |
	 | **             |
	 |*               |
	 |*               |
	 | **             |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x60,
	0x80,
	0x80,
	0x60,
	0x00,

	/* Character (0x64):
	 +----------------+
	 |   *            |
	 |   *            |
	 | ***            |
	 |*  *            |
	 |*  *            |
	 | ***            |
	 |                |
	 +----------------+ */
	0x10,
	0x10,
	0x70,
	0x90,
	0x90,
	0x70,
	0x00,

	/* Character (0x65):
	 +----------------+
	 |                |
	 |                |
	 | **             |
	 |* **            |
	 |**              |
	 | **             |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x60,
	0xb0,
	0xc0,
	0x60,
	0x00,

	/* Character (0x66):
	 +----------------+
	 |  *             |
	 | * *            |
	 | *              |
	 |***             |
	 | *              |
	 | *              |
	 |                |
	 +----------------+ */
	0x20,
	0x50,
	0x40,
	0xe0,
	0x40,
	0x40,
	0x00,

	/* Character (0x67):
	 +----------------+
	 |                |
	 |                |
	 | ***            |
	 |*  *            |
	 | **             |
	 |*               |
	 | ***            |
	 +----------------+ */
	0x00,
	0x00,
	0x70,
	0x90,
	0x60,
	0x80,
	0x70,

	/* Character (0x68):
	 +----------------+
	 |*               |
	 |*               |
	 |***             |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x80,
	0x80,
	0xe0,
	0x90,
	0x90,
	0x90,
	0x00,

	/* Character (0x69):
	 +----------------+
	 | *              |
	 |                |
	 |**              |
	 | *              |
	 | *              |
	 |***             |
	 |                |
	 +----------------+ */
	0x40,
	0x00,
	0xc0,
	0x40,
	0x40,
	0xe0,
	0x00,

	/* Character (0x6a):
	 +----------------+
	 |  *             |
	 |                |
	 |  *             |
	 |  *             |
	 |  *             |
	 |* *             |
	 | *              |
	 +----------------+ */
	0x20,
	0x00,
	0x20,
	0x20,
	0x20,
	0xa0,
	0x40,

	/* Character (0x6b):
	 +----------------+
	 |*               |
	 |*               |
	 |* *             |
	 |**              |
	 |* *             |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x80,
	0x80,
	0xa0,
	0xc0,
	0xa0,
	0x90,
	0x00,

	/* Character (0x6c):
	 +----------------+
	 |**              |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 |***             |
	 |                |
	 +----------------+ */
	0xc0,
	0x40,
	0x40,
	0x40,
	0x40,
	0xe0,
	0x00,

	/* Character (0x6d):
	 +----------------+
	 |                |
	 |                |
	 |* *             |
	 |****            |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0xa0,
	0xf0,
	0x90,
	0x90,
	0x00,

	/* Character (0x6e):
	 +----------------+
	 |                |
	 |                |
	 |***             |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0xe0,
	0x90,
	0x90,
	0x90,
	0x00,

	/* Character (0x6f):
	 +----------------+
	 |                |
	 |                |
	 | **             |
	 |*  *            |
	 |*  *            |
	 | **             |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x60,
	0x90,
	0x90,
	0x60,
	0x00,

	/* Character (0x70):
	 +----------------+
	 |                |
	 |                |
	 |***             |
	 |*  *            |
	 |*  *            |
	 |***             |
	 |*               |
	 +----------------+ */
	0x00,
	0x00,
	0xe0,
	0x90,
	0x90,
	0xe0,
	0x80,

	/* Character (0x71):
	 +----------------+
	 |                |
	 |                |
	 | ***            |
	 |*  *            |
	 |*  *            |
	 | ***            |
	 |   *            |
	 +----------------+ */
	0x00,
	0x00,
	0x70,
	0x90,
	0x90,
	0x70,
	0x10,

	/* Character (0x72):
	 +----------------+
	 |                |
	 |                |
	 |***             |
	 |*  *            |
	 |*               |
	 |*               |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0xe0,
	0x90,
	0x80,
	0x80,
	0x00,

	/* Character (0x73):
	   bbw=6, bbh=7, bbx=0, bby=-1, width=5
	 +----------------+
	 |                |
	 |                |
	 | ***            |
	 |**              |
	 |  **            |
	 |***             |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x70,
	0xc0,
	0x30,
	0xe0,
	0x00,

	/* Character (0x74):
	 +----------------+
	 | *              |
	 | *              |
	 |***             |
	 | *              |
	 | *              |
	 |  **            |
	 |                |
	 +----------------+ */
	0x40,
	0x40,
	0xe0,
	0x40,
	0x40,
	0x30,
	0x00,

	/* Character (0x75):
	 +----------------+
	 |                |
	 |                |
	 |*  *            |
	 |*  *            |
	 |*  *            |
	 | ***            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x90,
	0x90,
	0x90,
	0x70,
	0x00,

	/* Character (0x76):
	 +----------------+
	 |                |
	 |                |
	 |* *             |
	 |* *             |
	 |* *             |
	 | *              |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0xa0,
	0xa0,
	0xa0,
	0x40,
	0x00,

	/* Character (0x77):
	 +----------------+
	 |                |
	 |                |
	 |*  *            |
	 |*  *            |
	 |****            |
	 |****            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x90,
	0x90,
	0xf0,
	0xf0,
	0x00,

	/* Character (0x78):
	 +----------------+
	 |                |
	 |                |
	 |*  *            |
	 | **             |
	 | **             |
	 |*  *            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0x90,
	0x60,
	0x60,
	0x90,
	0x00,

	/* Character (0x79):
	 +----------------+
	 |                |
	 |                |
	 |*  *            |
	 |*  *            |
	 | * *            |
	 |  *             |
	 | *              |
	 +----------------+ */
	0x00,
	0x00,
	0x90,
	0x90,
	0x50,
	0x20,
	0x40,

	/* Character (0x7a):
	 +----------------+
	 |                |
	 |                |
	 |****            |
	 |  *             |
	 | *              |
	 |****            |
	 |                |
	 +----------------+ */
	0x00,
	0x00,
	0xf0,
	0x20,
	0x40,
	0xf0,
	0x00,

	/* Character (0x7b):
	 +----------------+
	 |  *             |
	 | *              |
	 |**              |
	 | *              |
	 | *              |
	 |  *             |
	 |                |
	 +----------------+ */
	0x20,
	0x40,
	0xc0,
	0x40,
	0x40,
	0x20,
	0x00,

	/* Character (0x7c):
	 +----------------+
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 | *              |
	 |                |
	 +----------------+ */
	0x40,
	0x40,
	0x40,
	0x40,
	0x40,
	0x40,
	0x00,

	/* Character (0x7d):
	   bbw=6, bbh=7, bbx=0, bby=-1, width=5
	 +----------------+
	 |*               |
	 | *              |
	 | **             |
	 | *              |
	 | *              |
	 |*               |
	 |                |
	 +----------------+ */
	0x80,
	0x40,
	0x60,
	0x40,
	0x40,
	0x80,
	0x00,

	/* Character (0x7e):
	 +----------------+
	 | * *            |
	 |* *             |
	 |                |
	 |                |
	 |                |
	 |                |
	 |                |
	 +----------------+ */
	0x50,
	0xa0,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00
}; 

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
