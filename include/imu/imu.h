/**
 * @addtogroup IMU Inertial Measurement Unit
 * @brief     Determines gesture recogniztion
 * @details   Has functions for determining compass directions, shaking
 *            and other movement of the device.
 * @{
 * @file      imu.h
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 15, 2015
 * @brief     Accelerometer and gyroscope libraries.
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   Accelerometer and gyroscope libraries containing the function
 *            prototype of the initialization function for the IMU. Also
 *            contains defines for IMU gyroscope, accelerometer, and megnetic
 *            sensor initialization.
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

#ifndef IMU_H_
#define IMU_H_

#include "reg-map.h"

///Register: CTRL_REG1_G(10h)
///Gyroscope Output Data Rate Selection
#define IMU_ODR_G_PD 0x00    ///<Power-Down Mode
#define IMU_ODR_G_15HZ 0x20  ///<14.9 Hz
#define IMU_ODR_G_60HZ 0x40  ///<59.9 Hz
#define IMU_ODR_G_119HZ 0x60 ///<119 Hz
#define IMU_ODR_G_238HZ 0x80 ///<238 Hz
#define IMU_ODR_G_476HZ 0xA0 ///<476 Hz
#define IMU_ODR_G_952HZ 0xC0 ///<952 Hz

///Gyroscope Full-Scale Selection
#define IMU_FS_G_245DPS 0x00  ///<245 dps
#define IMU_FS_G_500DPS 0x08  ///<500 dps
#define IMU_FS_G_2000DPS 0x18 ///<2000 dps

///Gyroscope Bandwidth Selection (Has to be done as a lookup table)
#warning values for bandwidth selection are incorrect

#define IMU_BW_G_14HZ 0x01  ///<14Hz bandwidth
#define IMU_BW_G_16HZ 0x02  ///<16Hz bandwidth
#define IMU_BW_G_21HZ 0x03  ///<21Hz bandwidth
#define IMU_BW_G_28HZ 0x04  ///<28Hz bandwidth
#define IMU_BW_G_29HZ 0x05  ///<29Hz bandwidth
#define IMU_BW_G_31HZ 0x06  ///<31Hz bandwidth
#define IMU_BW_G_33HZ 0x07  ///<33Hz bandwidth
#define IMU_BW_G_40HZ 0x08  ///<40Hz bandwidth
#define IMU_BW_G_57HZ 0x09  ///<57Hz bandwidth
#define IMU_BW_G_58HZ 0x0A  ///<58Hz bandwidth
#define IMU_BW_G_63HZ 0x0B  ///<63Hz bandwidth
#define IMU_BW_G_78HZ 0x0C  ///<78Hz bandwidth
#define IMU_BW_G_100HZ 0x0D ///<100Hz bandwidth

///Register: CTRL_REG2_G(11h)
///Gyroscope interrupt generator filter selection
#define IMU_INT_SEL_LOW_FILTER 0x00   ///<Lowpass filter
#define IMU_INT_SEL_BAND1_FILTER 0x40 ///<Bandpass filter wide
#define IMU_INT_SEL_BAND2_FILTER 0x10 ///<Bandpass filter narrow

///Gyroscope output filter selection
#define IMU_OUT_SEL_LOW_FILTER 0x00   ///<Lowpass filter
#define IMU_OUT_SEL_BAND1_FILTER 0x40 ///<Bandpass filter wide
#define IMU_OUT_SEL_BAND2_FILTER 0x10 ///<Bandpass filter narrow

///Register: CTRL_REG3_G
///











#endif /* IMU_H_ */

/// @}

