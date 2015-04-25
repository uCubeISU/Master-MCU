/**
 * @addtogroup I2C
 * @{
 * @file      I2C.h
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 16, 2015
 * @brief     Prototype for I2C functions
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   This file contains all the prototypes for I2C functions
 *            such as intialization, sending data, and recieving data
 *            for the Tiva MCU.
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

#ifndef I2C_H_
#define I2C_H_
/**
 * @class     i2c_t
 * @brief     A struct holding the base address of the i2c channel
 * @details   This struct is a 32 bit value representing the base address of the
 * 	          i2c channel. This struct is acting as an object to be used later.
 *
 */
typedef struct I2C_STRUCT
{
	/// The base address of the i2c channel.
	uint32_t base_addr;
}i2c_t;

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
i2c_t* I2C_init(uint32_t base_addr);

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
void I2C_send(i2c_t* this, uint8_t slave_addr, uint8_t data, uint8_t register_addr);

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
uint8_t I2C_receive(i2c_t* this, uint8_t slave_addr, uint8_t reg);



#endif /* I2C_H_ */

/// @}

