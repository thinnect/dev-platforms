/**
 * Platform IO configuration for TSB1
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#include "em_gpio.h"

#define PLATFORM_LED0_PORT gpioPortB
#define PLATFORM_LED0_PIN 12
#define PLATFORM_LED1_PORT gpioPortB
#define PLATFORM_LED1_PIN 11
#define PLATFORM_LED2_PORT gpioPortA
#define PLATFORM_LED2_PIN 5

#define PLATFORM_PIN1_PORT gpioPortA
#define PLATFORM_PIN1_PIN 0
#define PLATFORM_PIN2_PORT gpioPortA
#define PLATFORM_PIN2_PIN 1
#define PLATFORM_PIN3_PORT gpioPortA
#define PLATFORM_PIN3_PIN 2
#define PLATFORM_PIN4_PORT gpioPortA
#define PLATFORM_PIN4_PIN 3

#define PLATFORM_BUTTON_PORT gpioPortF
#define PLATFORM_BUTTON_PIN  4

#endif//PLATFORM_IO_H_
