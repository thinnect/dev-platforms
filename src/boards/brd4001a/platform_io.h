/**
 * Platform IO configuration for many SiLabs devkits.
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#include "bsp.h" // Make use of GPIO mappings already defined by SiLabs

#define PLATFORM_LED_COUNT 2
#define PLATFORM_LED0_PORT BSP_LED0_PORT
#define PLATFORM_LED0_PIN  BSP_LED0_PIN
#define PLATFORM_LED1_PORT BSP_LED1_PORT
#define PLATFORM_LED1_PIN  BSP_LED1_PIN

#define PLATFORM_PIN_COUNT 0
//#define PLATFORM_PIN1_PORT gpioPortA
//#define PLATFORM_PIN1_PIN 0
//#define PLATFORM_PIN2_PORT gpioPortA
//#define PLATFORM_PIN2_PIN 1
//#define PLATFORM_PIN3_PORT gpioPortA
//#define PLATFORM_PIN3_PIN 2
//#define PLATFORM_PIN4_PORT gpioPortA
//#define PLATFORM_PIN4_PIN 3

#define PLATFORM_BUTTON_PORT BSP_BUTTON0_PORT
#define PLATFORM_BUTTON_PIN  BSP_BUTTON0_PIN

#endif//PLATFORM_IO_H_
