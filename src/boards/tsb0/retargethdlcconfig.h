/**
 * HDLC data port configuration for tsb0.
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
 */
#ifndef RETARGETHDLCCONFIG_H_
#define RETARGETHDLCCONFIG_H_

#define SERIAL_HDLC_UART      USART1
#define SERIAL_HDLC_IRQ_NAME  USART1_RX_IRQHandler
#define SERIAL_HDLC_CLOCK     cmuClock_USART1
#define SERIAL_HDLC_IRQn      USART1_RX_IRQn

#if defined(HDLC_USE_JTAG_UART) // Onboard port shared with JTAG pins

#define SERIAL_HDLC_TXPORT    gpioPortF
#define SERIAL_HDLC_TXPIN     3
#define SERIAL_HDLC_TXLOC     USART_ROUTELOC0_TXLOC_LOC27
#define SERIAL_HDLC_RXPORT    gpioPortF
#define SERIAL_HDLC_RXPIN     0
#define SERIAL_HDLC_RXLOC     USART_ROUTELOC0_RXLOC_LOC23

#elif defined(HDLC_USE_EXTERNAL_UART) // First 2 pins in left header

#define SERIAL_HDLC_TXPORT    gpioPortA
#define SERIAL_HDLC_TXPIN     0
#define SERIAL_HDLC_TXLOC     USART_ROUTELOC0_TXLOC_LOC0
#define SERIAL_HDLC_RXPORT    gpioPortA
#define SERIAL_HDLC_RXPIN     1
#define SERIAL_HDLC_RXLOC     USART_ROUTELOC0_RXLOC_LOC0

#else // Use the non-JTAG uart

#define SERIAL_HDLC_TXPORT    gpioPortC
#define SERIAL_HDLC_TXPIN     7
#define SERIAL_HDLC_TXLOC     USART_ROUTELOC0_TXLOC_LOC12
#define SERIAL_HDLC_RXPORT    gpioPortB
#define SERIAL_HDLC_RXPIN     15
#define SERIAL_HDLC_RXLOC     USART_ROUTELOC0_RXLOC_LOC9

#endif//UART pin selection

#endif//RETARGETHDLCCONFIG_H_
