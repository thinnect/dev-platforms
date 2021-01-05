/**
 * SPI configuration for EB000034.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef RETARGETSPICONFIG_H_
#define RETARGETSPICONFIG_H_

#define RETARGET_SPI_UART       USART1
#define RETARGET_SPI_CLOCK      cmuClock_USART1
#define RETARGET_SPI_UART_INDEX 1
#define RETARGET_SPI_MISO_PORT  gpioPortA
#define RETARGET_SPI_MISO_PIN   5
#define RETARGET_SPI_MOSI_PORT  gpioPortA
#define RETARGET_SPI_MOSI_PIN   3
#define RETARGET_SPI_SCK_PORT   gpioPortA
#define RETARGET_SPI_SCK_PIN    0
#define RETARGET_SPI_CS_PORT    gpioPortA
#define RETARGET_SPI_CS_PIN     4

#endif//RETARGETSPICONFIG_H_
