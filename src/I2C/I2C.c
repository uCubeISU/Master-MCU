/**
 * @addtogroup I2C
 * @{
 * @file      I2C.c
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 16, 2015
 * @brief     I2C functions
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   This file contains all the I2C functions such as initialization,
 *            sending, and recieving data from the I2C bus.
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
#include <stdlib.h>
#include "i2c/I2C.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"

/**
 * @brief     Initialization for I2C0.
 * @memberof  i2c_t
 * @details   Initializes the I2C0 bus by enabling the I2C module 0. Resets
 *            the module, enables the master module, uses the system clock,
 *            and sets the data transfer rate.
 * @param     base_addr
 *                 32 bit integer representing the base address of the I2C bus
 * @return    this instantiated object
 */
i2c_t* I2C_init(uint32_t base_addr)
{

	i2c_t* this = malloc(sizeof(i2c_t));

	this->base_addr = base_addr;

    //enable I2C module 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

    //reset module
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    //Enable and initialize the I2C0 master module.  Use the system clock for
    //the I2C0 module.  The last parameter sets the I2C data transfer rate.
    //If false the data rate is set to 100kbps and if true the data rate will
    //be set to 400kbps.

    I2CMasterInitExpClk(this->base_addr, SysCtlClockGet(), true);


    return this;
}

/**
 * @brief     I2C send function
 * @memberof  i2c_t
 * @details   Sends data over the specified I2C bus line through function calls
 *            and given data and register addresses.
 * @param     slave_addr
 *                 8 bit integer representing the slave address to communicate with
 * @param     data
 *                 8 bit value to be passed over i2c
 * @param     register_Addr
 * 				   8 bit integer representing the register address to store data in.
 *
 */
void I2C_send(i2c_t* this, uint8_t slave_addr, uint8_t data, uint8_t register_addr)
{
	//Tell the master module what address it will place on the bus when communicating with slave.
	I2CMasterSlaveAddrSet(this->base_addr, slave_addr, false);

    //put next piece of data into I2C FIFO
    I2CMasterDataPut(this->base_addr, register_addr);

	//Initiate send of data from the MCU
	I2CMasterControl(this->base_addr, I2C_MASTER_CMD_BURST_SEND_START);

    //Wait until MCU is done transferring.
    while(I2CMasterBusy(this->base_addr));

    //put next piece of data into I2C FIFO
    I2CMasterDataPut(this->base_addr, data);

    //send next data that was just placed into FIFO
    I2CMasterControl(this->base_addr, I2C_MASTER_CMD_BURST_SEND_FINISH);

    // Wait until MCU is done transferring.
    while(I2CMasterBusy(this->base_addr));

}
/**
 * @brief     I2C recieve function
 * @memberof  i2c_t
 * @details   Allows the Master to recieve data from the slave by retrieving
 *            data from a specified address of the slave and transmitting that
 *            data back to the Master.
 * @param     slave_addr
 *                 8 bit integer representing the slave address to communicate with
 * @param	  reg
 * 				   8 bit integer representing the address fo the register to read from.
 * @return 	  The data that was pulled from the specified register
 */
uint8_t I2C_receive(i2c_t* this, uint8_t slave_addr, uint8_t reg)
{
    //specify that we are writing (a register address) to the
    //slave device
    I2CMasterSlaveAddrSet(this->base_addr, slave_addr, false);

    //specify register to be read
    I2CMasterDataPut(this->base_addr, reg);

    //send control byte and register address byte to slave device
    I2CMasterControl(this->base_addr, I2C_MASTER_CMD_BURST_SEND_START);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(this->base_addr));

    //specify that we are going to read from slave device
    I2CMasterSlaveAddrSet(this->base_addr, slave_addr, true);

    //send control byte and read from the register we
    //specified
    I2CMasterControl(this->base_addr, I2C_MASTER_CMD_SINGLE_RECEIVE);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(this->base_addr));

    //return data pulled from the specified register
    return I2CMasterDataGet(this->base_addr);
}

/// @}

