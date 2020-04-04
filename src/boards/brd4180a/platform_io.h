/**
 * Platform IO configuration for BRD4180A.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#define PLATFORM_LED_COUNT 2

#define PLATFORM_LED0_PORT gpioPortB
#define PLATFORM_LED0_PIN  0
#define PLATFORM_LED1_PORT gpioPortB
#define PLATFORM_LED1_PIN  1

#define PLATFORM_PIN_COUNT 0
//#define PLATFORM_PIN1_PORT gpioPortA
//#define PLATFORM_PIN1_PIN 0
//#define PLATFORM_PIN2_PORT gpioPortA
//#define PLATFORM_PIN2_PIN 1
//#define PLATFORM_PIN3_PORT gpioPortA
//#define PLATFORM_PIN3_PIN 2
//#define PLATFORM_PIN4_PORT gpioPortA
//#define PLATFORM_PIN4_PIN 3

// Buttons and LEDs are on the same GPIO - disable buttons
//#define PLATFORM_BUTTON_PORT BSP_BUTTON0_PORT
//#define PLATFORM_BUTTON_PIN  BSP_BUTTON0_PIN

#endif//PLATFORM_IO_H_
