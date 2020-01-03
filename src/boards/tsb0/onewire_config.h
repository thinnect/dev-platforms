/**
 * A sample Onewire config for the tsb0.
 *
 * NB: The pins are shared with the I2C configuration.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef ONEWIRE_CONFIG_H_
#define ONEWIRE_CONFIG_H_

#define ONEWIRE_PERIPHERAL_CLOCK 38400000LU

#define ONEWIRE_UART        USART1
#define ONEWIRE_UART_CLOCK  cmuClock_USART1
#define ONEWIRE_RX_PORT     gpioPortA
#define ONEWIRE_RX_PIN      1
#define ONEWIRE_TX_PORT     gpioPortA
#define ONEWIRE_TX_PIN      2
//#define ONEWIRE_TX_INVERTED

// Series 1
#define ONEWIRE_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC0
#define ONEWIRE_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC2

#define ONEWIRE_POWER_PORT  gpioPortA
#define ONEWIRE_POWER_PIN   0

#endif//ONEWIRE_CONFIG_H_
