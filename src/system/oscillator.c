/**
 * @addtogroup System
 * @{
 * @file      oscillator.c
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 15, 2015
 * @brief     Initialization function for main oscillator.
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   Contains the initialization function for the main oscillator.
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

#include "system/oscillator.h"
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"
/**
 * @brief     Initialization for main oscillator.
 * @details   Sets clock source to be the main oscillator. Sets system clock
 *            frequency to 50 MHz.
 * @todo      Edit this to set clock sources for peripherals and USB.
 */
void osc_init(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_5 |   // Divides System Clock by 5.
			       SYSCTL_USE_PLL |    // Selects to use PLL.
			       SYSCTL_XTAL_16MHZ | // Sets external crystal oscillator to 16MHz.
			       SYSCTL_OSC_MAIN);   // Use external crystal oscillator.
}

/// @}

