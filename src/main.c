/**
 * @addtogroup Main
 * @brief     The main source code and control loop of the project.
 * @{
 * @file      main.c
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 15, 2015
 * @brief     Main software control loop
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   Main entry point of the program, contains main control loop.
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

#include "oscillator.h"
#include "driverlib/systick.h"

void main_loop(void);

/**
 * @brief     Main entry point of the program.
 * @details   Initialize MCU, set up system tick and busy wait.
 */
int main(void)
{
	osc_init();                     //  Initialization for main oscillator
	SysTick.set(F_OSC/1000);        // Set system tick to 1 kHz
	SysTickIntRegister(main_loop);  // Register callback function for system tick
	SysTickIntEnable();             // Enable interrupt
	SysTickEnable();                // Enable system tick

}
/**
 * @brief     Main control loop.
 * @details   This function gets called once every millisecond and contains the
 *            main software control loop.
 * @todo      Impliment this
 */
void main_loop(void)
{
#warning main loop not implimented


}
/// @}

