/**
 * @addtogroup System
 * @{
 * @file      oscillator.h
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 15, 2015
 * @brief     Header file for oscillator family.
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   Contains prototype for all oscillator components.
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

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#define F_OSC 50000000

void osc_init(void); // Initialization for main oscillator.

#endif /* OSCILLATOR_H_ */

/// @}

