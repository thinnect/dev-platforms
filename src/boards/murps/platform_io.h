/**
 * Platform IO configuration for EB000034.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#include "em_gpio.h"

#define PLATFORM_LED_COUNT 3
#define PLATFORM_LED0_PORT gpioPortA
#define PLATFORM_LED0_PIN  6
#define PLATFORM_LED1_PORT gpioPortD
#define PLATFORM_LED1_PIN  4
#define PLATFORM_LED2_PORT gpioPortD
#define PLATFORM_LED2_PIN  3

#define PLATFORM_PIN_COUNT 0

#endif//PLATFORM_IO_H_
