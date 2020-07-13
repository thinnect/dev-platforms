/**
 * A sample Onewire config for the thinbox4.
 *
 * NB: The pins are shared with the I2C configuration.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef ONEWIRE_CONFIG_H_
#define ONEWIRE_CONFIG_H_

#define ONEWIRE_PERIPHERAL_CLOCK 38400000LU

#define ONEWIRE_UART_INDEX  1
#define ONEWIRE_UART        USART1
#define ONEWIRE_UART_CLOCK  cmuClock_USART1
#define ONEWIRE_PORT        gpioPortB
#define ONEWIRE_PIN         0
//#define ONEWIRE_TX_INVERTED

#define ONEWIRE_POWER_PORT  gpioPortB
#define ONEWIRE_POWER_PIN   1

#endif//ONEWIRE_CONFIG_H_
