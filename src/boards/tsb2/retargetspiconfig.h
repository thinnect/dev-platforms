#pragma once

// Configuration for thinbox3

#define RETARGET_SPI_UART       USART0
#define RETARGET_SPI_CLOCK      cmuClock_USART0
#define RETARGET_SPI_UART_INDEX 0
#define RETARGET_SPI_MISO_PORT  gpioPortA
#define RETARGET_SPI_MISO_PIN   3
#define RETARGET_SPI_MOSI_PORT  gpioPortA
#define RETARGET_SPI_MOSI_PIN   3
#define RETARGET_SPI_SCK_PORT   gpioPortA
#define RETARGET_SPI_SCK_PIN    0
#define RETARGET_SPI_CS_PORT    gpioPortA
#define RETARGET_SPI_CS_PIN     4
