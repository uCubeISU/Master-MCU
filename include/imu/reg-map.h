/**
 * @addtogroup IMU
 * @{
 * @file      reg-map.h
 * @author    Iowa State University uCube team
 * @author    Andy Snawerdt
 * @author    Jeramie Vens
 * @author    Kris Burney
 * @date      Mar 15, 2015
 * @brief     Header file for register mapping
 * @copyright Copyright (C) 2015 ISU uCube team
 * @details   Maps the registers address'.
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

#ifndef REG_MAP_H_
#define REG_MAP_H_

///@name Accelerometer and Gyroscope Register Address Defines
///@{
#define IMU_DEV_ADDR_GYRO_ACCEL 0x6A
#define IMU_REG_ADDR_ACT_THS 0x04
#define IMU_REG_ADDR_ACT_DUR 0X05
#define IMU_REG_ADDR_INT_GEN_CFG_XL 0x06
#define IMU_REG_ADDR_INT_GEN_THS_X_XL 0x07
#define IMU_REG_ADDR_INT_GEN_THS_Y_XL 0x08
#define IMU_REG_ADDR_INT_GEN_THS_Z_XL 0x09
#define IMU_REG_ADDR_INT_GEN_DUR_XL 0x0A
#define IMU_REG_ADDR_REFERENCE_G 0x0B
#define IMU_REG_ADDR_INT1_CTRL 0x0C
#define IMU_REG_ADDR_INT2_CTRL 0x0D
#define IMU_REG_ADDR_WHO_AM_I 0x0F
#define IMU_REG_ADDR_CTRL_REG1_G 0x10
#define IMU_REG_ADDR_CTRL_REG2_G 0x11
#define IMU_REG_ADDR_CTRL_REG3_G 0x12
#define IMU_REG_ADDR_ORIENT_CFG_G 0x13
#define IMU_REG_ADDR_INT_GEN_SRC_G 0x14
#define IMU_REG_ADDR_OUT_TEMP_L 0x15
#define IMU_REG_ADDR_OUT_TEMP_H 0x16
#define IMU_REG_ADDR_STATUS_REG1 0x17
#define IMU_REG_ADDR_OUT_X_L_G 0x18
#define IMU_REG_ADDR_OUT_X_H_G 0x19
#define IMU_REG_ADDR_OUT_Y_L_G 0x1A
#define IMU_REG_ADDR_OUT_Y_H_G 0x1B
#define IMU_REG_ADDR_OUT_Z_L_G 0x1C
#define IMU_REG_ADDR_OUT_Z_H_G 0x1D
#define IMU_REG_ADDR_CTRL_REG4_G 0x1E
#define IMU_REG_ADDR_CTRL_REG5_XL 0x1F
#define IMU_REG_ADDR_CTRL_REG6_XL 0x20
#define IMU_REG_ADDR_CTRL_REG7_XL 0x21
#define IMU_REG_ADDR_CTRL_REG8 0x22
#define IMU_REG_ADDR_CTRL_REG9 0x23
#define IMU_REG_ADDR_CTRL_REG10 0x24
#define IMU_REG_ADDR_INT_GEN_SRC_XL 0x26
#define IMU_REG_ADDR_STATUS_REG2 0x27
#define IMU_REG_ADDR_OUT_X_L_XL 0x28
#define IMU_REG_ADDR_OUT_X_H_XL 0x29
#define IMU_REG_ADDR_OUT_Y_L_XL 0x2A
#define IMU_REG_ADDR_OUT_Y_H_XL 0x2B
#define IMU_REG_ADDR_OUT_Z_L_XL 0x2C
#define IMU_REG_ADDR_OUT_Z_H_XL 0x2D
#define IMU_REG_ADDR_FIFO_CTRL 0x2E
#define IMU_REG_ADDR_FIFO_SRC 0x2D
#define IMU_REG_ADDR_INT_GEN_CFG_G 0x30
#define IMU_REG_ADDR_INT_GEN_THS_XH_G 0x31
#define IMU_REG_ADDR_INT_GEN_THS_XL_G 0x32
#define IMU_REG_ADDR_INT_GEN_THS_YH_G 0x33
#define IMU_REG_ADDR_INT_GEN_THS_YL_G 0x34
#define IMU_REG_ADDR_INT_GEN_THS_ZH_G 0x35
#define IMU_REG_ADDR_INT_GEN_THS_ZL_G 0x36
#define IMU_REG_ADDR_INT_GEN_DUR_G 0x37
///@}

///@name Magnetic Sensor Register Address Defines
///@{
#define IMU_DEV_ADDR_MAG 0x1C
#define IMU_REG_ADDR_OFFSET_X_REG_L_M 0x05
#define IMU_REG_ADDR_OFFSET_X_REG_H_M 0x06
#define IMU_REG_ADDR_OFFSET_Y_REG_L_M 0x07
#define IMU_REG_ADDR_OFFSET_Y_REG_H_M 0x08
#define IMU_REG_ADDR_OFFSET_Z_REG_L_M 0x09
#define IMU_REG_ADDR_OFFSET_Z_REG_H_M 0x0A
#define IMU_REG_ADDR_WHO_AM_I_M 0x0F
#define IMU_REG_ADDR_CTRL_REG1_M 0x20
#define IMU_REG_ADDR_CTRL_REG2_M 0x21
#define IMU_REG_ADDR_CTRL_REG3_M 0x22
#define IMU_REG_ADDR_CTRL_REG4_M 0x23
#define IMU_REG_ADDR_CTRL_REG5_M 0x24
#define IMU_REG_ADDR_STATUS_REG_M 0x27
#define IMU_REG_ADDR_OUT_X_L_M 0x28
#define IMU_REG_ADDR_OUT_X_H_M 0x29
#define IMU_REG_ADDR_OUT_Y_L_M 0x2A
#define IMU_REG_ADDR_OUT_Y_H_M 0x2B
#define IMU_REG_ADDR_OUT_Z_L_M 0x2C
#define IMU_REG_ADDR_OUT_Z_H_M 0x2D
#define IMU_REG_ADDR_INT_CFG_M 0x30
#define IMU_REG_ADDR_INT_SRC_M 0x31
#define IMU_REG_ADDR_INT_THS_L_M 0x32
#define IMU_REG_ADDR_INT_THS_H_M 0x33
///@}

#endif /* REG_MAP_H_ */

/// @}

