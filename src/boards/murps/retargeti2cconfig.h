/**
 * I2C configuration for murps and the RaspberryPi connector.
 *
 * Copyright Thinnect Inc. 2021
 * @license MIT
 */

 #include "em_i2c.h"

#ifndef RETARGETI2CCONFIG_H_
#define RETARGETI2CCONFIG_H_

#define RETARGET_I2C_INDEX       0
#define RETARGET_I2C_DEV         I2C0
#define RETARGET_I2C_CLOCK       cmuClock_I2C0

#define RETARGET_I2C_SDA_PORT    gpioPortD
#define RETARGET_I2C_SDA_PIN     2
#define RETARGET_I2C_SCL_PORT    gpioPortD
#define RETARGET_I2C_SCL_PIN     1

#endif//RETARGETI2CCONFIG_H_
