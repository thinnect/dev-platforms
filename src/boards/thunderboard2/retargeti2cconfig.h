// Sample I2C configuration for Silicon Labs Thunderboard 2.

// Source: https://www.silabs.com/documents/public/data-sheets/efr32mg12-datasheet.pdf

#ifndef RETARGETI2CCONFIG_H_
#define RETARGETI2CCONFIG_H_

#define RETARGET_I2C_DEV         I2C1
#define RETARGET_I2C_CLOCK       cmuClock_I2C1

#define RETARGET_I2C_SDA_PORT    gpioPortC
#define RETARGET_I2C_SDA_PIN     4
#define RETARGET_I2C_SCL_PORT    gpioPortC
#define RETARGET_I2C_SCL_PIN     5
#define RETARGET_I2C_PWR_PORT    gpioPortF
#define RETARGET_I2C_PWR_PIN     9

#define RETARGET_I2C_SDA_LOC     I2C_ROUTELOC0_SDALOC_LOC17 
#define RETARGET_I2C_SCL_LOC     I2C_ROUTELOC0_SCLLOC_LOC17  

#endif//RETARGETI2CCONFIG_H_
