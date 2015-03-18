/**
 * @addtogroup frame.h
 * @{
 * @file      frame.h
 * @author    Iowa State University uCube team
 * @author    Kristopher
 * @date      Mar 17, 2015
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
#ifndef INCLUDE_DISPLAY_FRAME_H_
#define INCLUDE_DISPLAY_FRAME_H_



void setAllSubFrames(/*type large enough to hold value*/ cubeValue);
void setFrame(int frameNum, uint16_t frameValue);



#endif /* INCLUDE_DISPLAY_FRAME_H_ */
