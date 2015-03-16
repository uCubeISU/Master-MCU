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

#include "imu/imu.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2c/I2C.h"


/**
 * @brief     Initialization for IMU.
 * @details   Initializes the accelerometer, gyroscope, and magnetic sensor.
 *            More details on a specific initialization of one of those
 *            three sensors can be found in the function associated with
 *            initializing that inparticular sensor.
 */
void imu_init(void)
{
    //enable GPIO peripheral that contains I2C0
    SysCtlPeripheralEnable();

	//Pins that matter: DEN_A/G = PH4
	//DRDY_M = PG5
	//INT_M  = PH7
    //INT1_A/G = PH6
    //INT2_A/G = PH5

    //Configure the pin muxing for I2C0 functions. (These ports will change!)
    GPIOPinConfigure();
    GPIOPinConfigure();

    //Select the I2C function for these pins. (These ports and pins will change!)
    GPIOPinTypeI2CSCL();
    GPIOPinTypeI2C();

	gyro_init();
	accel_init();
}
/**
 * @brief     Initialization for Gyroscope.
 * @details   Initializes the Gyroscope for:
 *
 * @todo      Determine what settings we need for gyroscope initialization.
 */
void gyro_init(uint8_t CTRL_REG1_DATA_G, uint8_t CTRL_REG2_DATA_G, uint8_t CTRL_REG3_DATA_G, uint8_t CTRL_REG4_DATA_G)
{
	I2C_init();
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG1_DATA_G, IMU_REG_ADDR_CTRL_REG1_G);
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG2_DATA_G, IMU_REG_ADDR_CTRL_REG2_G);
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG3_DATA_G, IMU_REG_ADDR_CTRL_REG3_G);
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG4_DATA_G, IMU_REG_ADDR_CTRL_REG4_G);
}
/**
 * @brief     Initialization for Accelerometer.
 * @details   Initializes the Accelerometer for:
 *
 * @todo      Determine what settings we need for accelerometer initialization.
 */
void accel_init(uint8_t CTRL_REG5_DATA_XL, uint8_t CTRL_REG6_DATA_XL, uint8_t CTRL_REG7_DATA_XL)
{
	I2C_init();
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG5_DATA_XL, IMU_REG_ADDR_CTRL_REG5_XL);
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG6_DATA_XL, IMU_REG_ADDR_CTRL_REG6_XL);
	I2C_send(IMU_DEV_ADDR_GYRO_ACCEL, CTRL_REG7_DATA_XL, IMU_REG_ADDR_CTRL_REG7_XL);
}
/**
 * @brief     Initialization for Magnet Sensor.
 * @details   Initializes the Magnet Sensor for:
 *
 * @todo      Determine what settings we need for magnet sensor initialization.
 */
void magnet_init()
{

}

/// @}

