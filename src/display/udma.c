/**
 * @addtogroup Display
 * @{
 * @file      udma.c
 * @author    Iowa State University uCube team
 * @author    Kristopher
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @date      Mar 17, 2015
 * @brief     micro direct memory access
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   contains initialization functions for udma
 */

/*
    Master-MCU
    Copyright (C) 2015  Iowa State University uCube team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pz.h"
#include "driverlib/udma.h"

/*
 * channel number and information is found in driverlib/udma.h
 */

void udma_init(uint8_t I2C_CHAN_NUM)
{

	uDMAChannelAssign(I2C_CHAN_NUM);
	uDMAChannelAttributeEnable(I2C_CHAN_NUM, UDMA_ATTR_USEBURST);
	uDMAChannelControlSet(I2C_CHAN_NUM | UDMA_PRI_SELECT, UDMA_SIZE_8 |
			                                                  UDMA_SRC_INC_8 |
			                                                  UDMA_DST_INC_NONE);
	uDMAChannelEnable(I2C_CHAN_NUM);
}


/// @}



