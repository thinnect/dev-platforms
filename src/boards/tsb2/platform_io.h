/**
 * Platform IO configuration for TSB2
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
 */

#ifndef PLATFORM_IO_H_
#define PLATFORM_IO_H_

#include "em_gpio.h"
#include "em_adc.h"

#define PLATFORM_LED_COUNT 3
#define PLATFORM_LED0_PORT gpioPortD
#define PLATFORM_LED0_PIN  4
#define PLATFORM_LED1_PORT gpioPortC
#define PLATFORM_LED1_PIN  2
#define PLATFORM_LED2_PORT gpioPortD
#define PLATFORM_LED2_PIN  2

#define PLATFORM_PIN_COUNT 4
#define PLATFORM_PIN1_PORT gpioPortB
#define PLATFORM_PIN1_PIN  1
#define PLATFORM_PIN2_PORT gpioPortB
#define PLATFORM_PIN2_PIN  0
#define PLATFORM_PIN3_PORT gpioPortA
#define PLATFORM_PIN3_PIN  5
#define PLATFORM_PIN4_PORT gpioPortA
#define PLATFORM_PIN4_PIN  6

#define PLATFORM_BUTTON_PORT gpioPortC
#define PLATFORM_BUTTON_PIN  3

#define PLATFORM_I2C_COUNT 1
#define PLATFORM_I2CS { I2C0 }

#define PLATFORM_ADC_COUNT 1
#define PLATFORM_ADCS { ADC0 }

#endif//PLATFORM_IO_H_
