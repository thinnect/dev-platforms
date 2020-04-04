/**
 * HDLC data port configuration for BRD4180A.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef RETARGETHDLCCONFIG_H_
#define RETARGETHDLCCONFIG_H_

#if defined(HDLC_USE_VCOM_UART) // Mainboard VCOM port

// NB: The VCOM also needs to be activated, which is currently always done
// by retargetserial (provided RETARGET_VCOM is defined) and even if the other
// defined port is used. However if that were to change, VCOM would stop working
// for HDLC.

#define SERIAL_HDLC_UART        USART0
#define SERIAL_HDLC_IRQ_NAME    USART0_RX_IRQHandler
#define SERIAL_HDLC_CLOCK       cmuClock_USART0
#define SERIAL_HDLC_IRQn        USART0_RX_IRQn
#define SERIAL_HDLC_UART_INDEX  0
#define SERIAL_HDLC_TXPORT      gpioPortA
#define SERIAL_HDLC_TXPIN       5
#define SERIAL_HDLC_RXPORT      gpioPortA
#define SERIAL_HDLC_RXPIN       6

#else // Use the "external" UART

#define SERIAL_HDLC_UART        USART1
#define SERIAL_HDLC_IRQ_NAME    USART1_RX_IRQHandler
#define SERIAL_HDLC_CLOCK       cmuClock_USART1
#define SERIAL_HDLC_IRQn        USART1_RX_IRQn
#define SERIAL_HDLC_UART_INDEX  1
#define SERIAL_HDLC_TXPORT      gpioPortB
#define SERIAL_HDLC_TXPIN       0
#define SERIAL_HDLC_RXPORT      gpioPortB
#define SERIAL_HDLC_RXPIN       1

#endif//UART pin selection

#endif//RETARGETHDLCCONFIG_H_
