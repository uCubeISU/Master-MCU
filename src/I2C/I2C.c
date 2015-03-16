/**
 * @addtogroup <group name>
 * @{
 * @file      I2C.c
 * @author    Iowa State University uCube team
 * @author    Sprog
 * @date      Mar 16, 2015
 * @brief     <brief description>
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   <detailed description>
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
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"

#define IMU_BASE_ADDR I2C0_BASE //change for correct I2C for IMU
/**
 * @brief     Initialization for I2Cx.
 * @details   Initializes the I2Cx bus by enabling the I2C module x. Resets
 *            the module, enables the master module, uses the system clock,
 *            and sets the data transfer rate.
 *
 * @todo      Determine what I2C module we are using. Determine what ports and
 *            pins we are accessing from the IMU
 */
void I2C_init(void)
{
    //enable I2C module 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

    //reset module
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    //Enable and initialize the I2C0 master module.  Use the system clock for
    //the I2C0 module.  The last parameter sets the I2C data transfer rate.
    //If false the data rate is set to 100kbps and if true the data rate will
    //be set to 400kbps.
    I2CMasterInitExpClk(IMU_BASE_ADDR, SysCtlClockGet(), true);
}

/**
 * @brief     I2C send function
 * @details   Sends data over the specified I2C bus line through function calls
 *            and given data and register addresses.
 */
void I2C_send(uint8_t slave_addr, uint8_t data, uint8_t register_addr)
{
	//Tell the master module what address it will place on the bus when communicating with slave.
	I2CMasterSlaveAddrSet(IMU_BASE_ADDR, slave_addr, false);

    //put next piece of data into I2C FIFO
    I2CMasterDataPut(IMU_BASE_ADDR, register_addr);

	//Initiate send of data from the MCU
	I2CMasterControl(IMU_BASE_ADDR, I2C_MASTER_CMD_BURST_SEND_START);

    //Wait until MCU is done transferring.
    while(I2CMasterBusy(IMU_BASE_ADDR));

    //put next piece of data into I2C FIFO
    I2CMasterDataPut(IMU_BASE_ADDR, data);

    //send next data that was just placed into FIFO
    I2CMasterControl(IMU_BASE_ADDR, I2C_MASTER_CMD_BURST_SEND_FINISH);

    // Wait until MCU is done transferring.
    while(I2CMasterBusy(IMU_BASE_ADDR));

}
/**
 * @brief     I2C recieve function
 * @details   Allows the Master to recieve data from the slave by retrieving
 *            data from a specified address of the slave and transmitting that
 *            data back to the Master.
 */
uint8_t I2C_receive(uint8_t slave_addr, uint8_t reg)
{
    //specify that we are writing (a register address) to the
    //slave device
    I2CMasterSlaveAddrSet(IMU_BASE_ADDR, slave_addr, false);

    //specify register to be read
    I2CMasterDataPut(IMU_BASE_ADDR, reg);

    //send control byte and register address byte to slave device
    I2CMasterControl(IMU_BASE_ADDR, I2C_MASTER_CMD_BURST_SEND_START);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(IMU_BASE_ADDR));

    //specify that we are going to read from slave device
    I2CMasterSlaveAddrSet(IMU_BASE_ADDR, slave_addr, true);

    //send control byte and read from the register we
    //specified
    I2CMasterControl(IMU_BASE_ADDR, I2C_MASTER_CMD_SINGLE_RECEIVE);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(IMU_BASE_ADDR));

    //return data pulled from the specified register
    return I2CMasterDataGet(IMU_BASE_ADDR);
}

/// @}

