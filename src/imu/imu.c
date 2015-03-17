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
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"


/**
 * @brief     Initialization for IMU.
 * @details   Initializes the accelerometer, gyroscope, and magnetic sensor.
 *            More details on a specific initialization of one of those
 *            three sensors can be found in the function associated with
 *            initializing that inparticular sensor.
 */
void imu_init(void)
{

    //enable I2C module 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

    //reset module
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    //enable GPIO peripherals
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG); //enable port G
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH); //enable port H
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); //enable port B

    //configure pin muxing.
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_4); //set PH4 as output
    GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_7 | GPIO_PIN_6 | GPIO_PIN_5); //set PH7, PH6, and PH5 as input
    GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, GPIO_PIN_5); //set PG5 as input
    GPIOPinConfigure(GPIO_PB2_I2C0SCL); //set PB2 to be I2C0SCL
    GPIOPinConfigure(GPIO_PB3_I2C0SDA); //set PB3 to be I2C0SDA

	gyro_init();
	accel_init();
}
/**
 * @brief     Initialization for Gyroscope.
 * @details   Initializes the Gyroscope for:
 *
 * @param     CTRL_REG1_DATA_G
 *                 8 bit value containing the data to be stored in the register
 * @param     CTRL_REG2_DATA_G
 *                 8 bit value containing the data to be stored in the register
 * @param     CTRL_REG3_DATA_G
 *                 8 bit value containing the data to be stored in the register
 * @param     CTRL_REG4_DATA_G
 *                 8 bit value containing the data to be stored in the register
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
 * @param     CTRL_REG5_DATA_XL
 *                 8 bit value containing the data to be stored in the register
 * @param     CTRL_REG6_DATA_XL
 *                 8 bit value containing the data to be stored in the register
 * @param     CTRL_REG7_DATA_XL
 *                 8 bit value containing the data to be stored in the register
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

