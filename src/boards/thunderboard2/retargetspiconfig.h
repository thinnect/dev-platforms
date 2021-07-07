// Sample SPI configuration for Silicon Labs Thunderboard 2

// Source: https://www.silabs.com/documents/public/schematic-files/TBSense2-BRD4166A-D00-schematic.pdf

#ifndef RETARGETSPICONFIG_H_
#define RETARGETSPICONFIG_H_

#define RETARGET_SPI_UART      USART2
#define RETARGET_SPI_CLOCK     cmuClock_USART2
#define RETARGET_SPI_MISO_PORT gpioPortK
#define RETARGET_SPI_MISO_PIN  2
#define RETARGET_SPI_MOSI_PORT gpioPortK
#define RETARGET_SPI_MOSI_PIN  0
#define RETARGET_SPI_SCK_PORT  gpioPortF
#define RETARGET_SPI_SCK_PIN   7
#define RETARGET_SPI_CS_PORT   gpioPortK
#define RETARGET_SPI_CS_PIN    1
#define RETARGET_SPI_RX_LOC    USART_ROUTELOC0_RXLOC_LOC30
#define RETARGET_SPI_TX_LOC    USART_ROUTELOC0_TXLOC_LOC29
#define RETARGET_SPI_CLK_LOC   USART_ROUTELOC0_CLKLOC_LOC18 

#endif//RETARGETSPICONFIG_H_
