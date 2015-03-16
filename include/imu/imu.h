/**
 * @addtogroup IMU Inertial Measurement Unit
 * @brief     Determines gesture recogniztion
 * @details   Prototypes functions for determining compass directions, shaking
 *            and other movement of the device. Contains prototypes for
 *            the initialization functions of the IMU as well as Macros for
 *            control registers 1-7 and 9.
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
 *            prototype of the initialization functions for the IMU. Also
 *            contains defines for IMU gyroscope, accelerometer, and magnetic
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
#include <stdint.h>

void imu_init(void);
void gyro_init(uint8_t CTRL_REG1_G, uint8_t CTRL_REG2_G, uint8_t CTRL_REG3_G, uint8_t CTRL_REG4_G);
void accel_init(uint8_t CTRL_REG5_XL, uint8_t CTRL_REG6_XL, uint8_t CTRL_REG7_XL);

// Register: CTRL_REG1_G
///@name Gyroscope Output Data Rate Selection
///@{
#define IMU_ODR_PD_G 0x00    ///<Power-Down Mode
#define IMU_ODR_15HZ_G 0x20  ///<14.9 Hz
#define IMU_ODR_60HZ_G 0x40  ///<59.9 Hz
#define IMU_ODR_119HZ_G 0x60 ///<119 Hz
#define IMU_ODR_238HZ_G 0x80 ///<238 Hz
#define IMU_ODR_476HZ_G 0xA0 ///<476 Hz
#define IMU_ODR_952HZ_G 0xC0 ///<952 Hz
///@}

///@name Gyroscope Full-Scale Selection
///@{
#define IMU_FS_245DPS_G 0x00  ///<245 dps
#define IMU_FS_500DPS_G 0x08  ///<500 dps
#define IMU_FS_2000DPS_G 0x18 ///<2000 dps
///@}

///@name Gyroscope Bandwidth Selection (Lookup Table- Page 46 of datasheet)
///@{
#warning values for bandwidth selection are dependant on the lookup table

#define IMU_BW_14HZ_G 0x01  ///<14Hz bandwidth
#define IMU_BW_16HZ_G 0x02  ///<16Hz bandwidth
#define IMU_BW_21HZ_G 0x03  ///<21Hz bandwidth
#define IMU_BW_28HZ_G 0x04  ///<28Hz bandwidth
#define IMU_BW_29HZ_G 0x05  ///<29Hz bandwidth
#define IMU_BW_31HZ_G 0x06  ///<31Hz bandwidth
#define IMU_BW_33HZ_G 0x07  ///<33Hz bandwidth
#define IMU_BW_40HZ_G 0x08  ///<40Hz bandwidth
#define IMU_BW_57HZ_G 0x09  ///<57Hz bandwidth
#define IMU_BW_58HZ_G 0x0A  ///<58Hz bandwidth
#define IMU_BW_63HZ_G 0x0B  ///<63Hz bandwidth
#define IMU_BW_78HZ_G 0x0C  ///<78Hz bandwidth
#define IMU_BW_100HZ_G 0x0D ///<100Hz bandwidth
///@}

//Register: CTRL_REG2_G
///@name Gyroscope Interrupt Generator Filter Selection
///@{
#define IMU_INT_SEL_LP_FILTER_G 0x00   ///<Lowpass filter
#define IMU_INT_SEL_BP1_FILTER_G 0x40 ///<Bandpass filter wide
#define IMU_INT_SEL_BP2_FILTER_G 0x10 ///<Bandpass filter narrow
///@}

///@name Gyroscope Output Filter Selection
///@{
#define IMU_OUT_SEL_LP_FILTER_G 0x00  ///<Lowpass filter
#define IMU_OUT_SEL_BP1_FILTER_G 0x40 ///<Bandpass filter wide
#define IMU_OUT_SEL_BP2_FILTER_G 0x10 ///<Bandpass filter narrow
///@}

//Register: CTRL_REG3_G
///@name Gyroscope Low-Power Mode Enable
///@{
#define IMU_LP_Mode_DIS_G 0x00 ///<Low-Power mode disabled
#define IMU_LP_MODE_EN_G 0x80  ///<Low-Power mode enabled
///@}

///@name Gyroscope High-Pass Filter Enable
///@{
#define IMU_HP_FILTER_DIS_G 0x00 ///<High-Pass filter disabled
#define IMU_HP_FILTER_EN_G 0x40  ///<High-Pass filter enable
///@}

///@name Gyroscope High-Pass Filter Cutoff Frequency (Lookup Table - Page 48 of datasheet)
///@{
#define IMU_HPCF_H0_G 0x00 ///<High-Pass filter cutoff frequency row 1
#define IMU_HPCF_H1_G 0x01 ///<High-Pass filter cutoff frequency row 2
#define IMU_HPCF_H2_G 0x02 ///<High-Pass filter cutoff frequency row 3
#define IMU_HPCF_H3_G 0x03 ///<High-Pass filter cutoff frequency row 4
#define IMU_HPCF_H4_G 0x04 ///<High-Pass filter cutoff frequency row 5
#define IMU_HPCF_H5_G 0x05 ///<High-Pass filter cutoff frequency row 6
#define IMU_HPCF_H6_G 0x06 ///<High-Pass filter cutoff frequency row 7
#define IMU_HPCF_H7_G 0x07 ///<High-Pass filter cutoff frequency row 8
#define IMU_HPCF_H8_G 0x08 ///<High-Pass filter cutoff frequency row 9
#define IMU_HPCF_H9_G 0x09 ///<High-Pass filter cutoff frequency row 10
///@}

//CTRL_REG4_G
///@name Gyroscope Axis Output Enable
///@{
#define IMU_Z_AXIS_DIS_G 0x00 ///<Z-axis output disabled
#define IMU_Z_AXIS_EN_G 0x20  ///<Z-axis output enabled
#define IMU_Y_AXIS_DIS_G 0x00 ///<Y-axis output disabled
#define IMU_Y_AXIS_EN_G 0x10  ///<Y-axis output enabled
#define IMU_X_AXIS_DIS_G 0x00 ///<X-axis output disabled
#define IMU_X_AXIS_EN_G 0x08  ///<X-axis output enabled
///@}


//CTRL_REG5_XL
///@name Accelerometer Decimation of Acceleration Data
///@{
#define IMU_DEC_NODEC_XL 0x00    ///<No decimation of data
#define IMU_DEC_2SAMPLES_XL 0x40 ///<Update every 2 samples
#define IMU_DEC_4SAMPLES_XL 0x80 ///<Update every 4 samples
#define IMU_DEC_8SAMPLES_XL 0xC0 ///<Update every 8 samples
///@}

///@name Accelerometer Axis Output Enable
///@{
#define IMU_Z_AXIS_DIS_XL 0x00 ///<Z-axis output disabled
#define IMU_Z_AXIS_EN_XL 0x20  ///<Z-axis output enabled
#define IMU_Y_AXIS_DIS_XL 0x00 ///<Y-axis output disabled
#define IMU_Y_AXIS_EN_XL 0x10  ///<Y-axis output enabled
#define IMU_X_AXIS_DIS_XL 0x00 ///<X-axis output disabled
#define IMU_X_AXIS_EN_XL 0x08  ///<X-axis output enabled
///@}

//CTRL_REG6_XL
///@name Accelerometer Output Data Rate Selection
///@{
#define IMU_ODR_PD_XL 0x00    ///<Power-Down Mode
#define IMU_ODR_10HZ_XL 0x20  ///<10 Hz
#define IMU_ODR_50HZ_XL 0x40  ///<50 Hz
#define IMU_ODR_119HZ_XL 0x60 ///<119 Hz
#define IMU_ODR_238HZ_XL 0x80 ///<238 Hz
#define IMU_ODR_476HZ_XL 0xA0 ///<476 Hz
#define IMU_ODR_952HZ_XL 0xC0 ///<952 Hz
///@}

///@name Accelerometer Full-Scale Selection
///@{
#define IMU_FS_2G_XL 0x00  ///<-2G to 2G of data
#define IMU_FS_16G_XL 0x08 ///<-16G to 16G of data
#define IMU_FS_10G_XL 0x10 ///<-10G to 10G of data
#define IMU_FS_8G_XL 0x18  ///<-8G to 8G of data
///@}

///@name Accelerometer Bandwidth selection through ODR Enable (Lookup Table - Page 52 of datasheet)
///@{
#define IMU_BW_SCAL_ODR_XL 0x00 ///<Bandwidth selection is based on ODR selection
#define IMU_BW_SCAL_NOT_ODR_XL 0x04 ///<Bandwidth selection is according to BW_XL
//@}

///@name Accelerometer Bandwidth Selection
///@{
#define IMU_BW_408HZ_XL 0x00 ///<408Hz bandwidth
#define IMU_BW_211HZ_XL      ///<211Hz bandwidth
#define IMU_BW_105HZ_XL      ///<105Hz bandwidth
#define IMU_BW_50HZ_XL       ///<50Hz bandwidth
///@}

//CTRL_REG7_XL
///@name Accelerometer High Resolution Enable
///@{
#define IMU_HR_DIS_XL 0x00 ///<Disable High Resolution Mode
#define IMU_HR_EN_XL 0x80  ///<Enable High Resolution Mode
///@}

///@name Accelerometer Digital Filter high pass and low pass (only applicable if high resolution mode is enabled)
///@{
#define IMU_DCF_ODR_50 0x00  ///<bandwidth of high pass filter is ODR value divided by 50
#define IMU_DCF_ODR_100 0x20 ///<bandwidth of high pass filter is ODR value divided by 100
#define IMU_DCF_ODR_9 0x40   ///<bandwidth of high pass filter is ODR value divided by 9
#define IMU_DCF_ODR_400 0x60 ///<bandwidth of high pass filter is ODR value divided by 400
///@}

//CTRL_REG9_G
///@name Gyroscope Sleep Enable
///@{
#define IMU_SLEEP_DIS_G 0x00 ///<Gyroscope sleep mode disabled
#define IMU_SLEEP_EN_G 0x40  ///<Gyroscope sleep mode enabled
///@}
#endif /* IMU_H_ */

/// @}

