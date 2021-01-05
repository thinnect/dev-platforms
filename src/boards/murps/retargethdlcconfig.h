/**
 * HDLC data port configuration for EB000034.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef RETARGETHDLCCONFIG_H_
#define RETARGETHDLCCONFIG_H_

#include "em_gpio.h"
#include "em_usart.h"

#define SERIAL_HDLC_UART        USART0
#define SERIAL_HDLC_IRQ_NAME    USART0_RX_IRQHandler
#define SERIAL_HDLC_CLOCK       cmuClock_USART0
#define SERIAL_HDLC_IRQn        USART0_RX_IRQn
#define SERIAL_HDLC_UART_INDEX  0
#define SERIAL_HDLC_TXPORT      gpioPortC
#define SERIAL_HDLC_TXPIN       1
#define SERIAL_HDLC_RXPORT      gpioPortC
#define SERIAL_HDLC_RXPIN       0

#endif//RETARGETHDLCCONFIG_H_
