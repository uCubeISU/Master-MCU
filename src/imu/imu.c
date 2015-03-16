/**
 * @addtogroup IMU
 * @{
 * @file      imu.c
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 15, 2015
 * @brief     Initialization of the IMU
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   Initialization of the accelerometer and gyroscope
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

#include "imu.h"
#include <stdint.h>

/**
 * @brief     Initialization for IMU.
 * @details   Initializes the accelerometer, gyroscope, and magnetic sensor.
 *            More details on a specific initialization of one of those
 *            three sensors can be found in the function associated with
 *            initializing that in particular sensor.
 */
void imu_init(void)
{

}
/**
 * @brief     Initialization for Gyroscope.
 * @details   Initializes the Gyroscope for:
 *
 * @todo      Determine what settings we need for gyroscope initialization and do I2C communication.
 */
void gyro_init(uint8_t CTRL_REG1_G, uint8_t CTRL_REG2_G, uint8_t CTRL_REG3_G, uint8_t CTRL_REG4_G)
{

}
/**
 * @brief     Initialization for Accelerometer.
 * @details   Initializes the Accelerometer for:
 *
 * @todo      Determine what settings we need for accelerometer initialization and do I2C communication.
 */
void accel_init(uint8_t CTRL_REG5_XL, uint8_t CTRL_REG6_XL, uint8_t CTRL_REG7_XL)
{

}
/// @}

