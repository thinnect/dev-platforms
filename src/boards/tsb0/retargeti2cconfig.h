/**
 * Sample I2C configuration for tsb0.
 *
 * NB: The pins are shared with the OneWire configuration.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef RETARGETI2CCONFIG_H_
#define RETARGETI2CCONFIG_H_

#define RETARGET_I2C_DEV         I2C0
#define RETARGET_I2C_CLOCK       cmuClock_I2C0

#define RETARGET_I2C_SDA_PORT    gpioPortA
#define RETARGET_I2C_SDA_PIN     1
#define RETARGET_I2C_SCL_PORT    gpioPortA
#define RETARGET_I2C_SCL_PIN     2
#define RETARGET_I2C_PWR_PORT    gpioPortA
#define RETARGET_I2C_PWR_PIN     0

#define RETARGET_I2C_SDA_LOC     I2C_ROUTELOC0_SDALOC_LOC1
#define RETARGET_I2C_SCL_LOC     I2C_ROUTELOC0_SCLLOC_LOC1

#endif//RETARGETI2CCONFIG_H_
