/*
 * @Author: Sorzn
 * @Date: 2019-11-22 13:38:31
 * @LastEditTime: 2019-11-22 14:33:56
 * @Description: M5Stack Hat BUGC Lib
 * @FilePath: /M5StickC/examples/Hat/BUGC/bugC.h
 */

#ifndef __BUG_C_H
#define __BUG_C_H

#include "Arduino.h"

#define BUGC_ADDR 0x38

#define FRONT_LEFT  0
#define FRONT_RIGHT 1
#define REAR_LEFT   2
#define REAR_RIGHT  3

/**
 * @description: Set BugC single motor speed
 * @param pos: 0 ~ 3
 * @param speed: -100 ~ 100
 * @return: 
 */
extern void BugCSetSpeed(uint8_t pos, int8_t speed);

/**
 * @description: Set BugC motor speed
 * @param speed_0: -100 ~ 100
 * @param speed_1: -100 ~ 100 
 * @param speed_2: -100 ~ 100 
 * @param speed_3: -100 ~ 100
 * @return: 
 */
extern void BugCSetAllSpeed(int8_t speed_0, int8_t speed_1, int8_t speed_2, int8_t speed_3);

/**
 * @description: Set BugC sk6812 color
 * @param color_left: (r << 16) | (g << 8) | b
 * @param color_right: (r << 16) | (g << 8) | b
 * @return: 
 */
extern void BugCSetColor(uint32_t color_left, uint32_t color_right);

#endif