/**
 * Debug UART configuration for EB000034.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef RETARGETSERIALCONFIG_H_
#define RETARGETSERIALCONFIG_H_

#define RETARGET_UART        USART2
#define RETARGET_IRQ_NAME    USART2_RX_IRQHandler
#define RETARGET_CLK         cmuClock_USART2
#define RETARGET_IRQn        USART2_RX_IRQn
#define RETARGET_TX          USART_Tx
#define RETARGET_RX          USART_Rx
#define RETARGET_UART_INDEX  2
#define RETARGET_TXPORT      gpioPortC
#define RETARGET_TXPIN       4
#define RETARGET_RXPORT      gpioPortC
#define RETARGET_RXPIN       5

#define LOGGER_LDMA_USART2

#define RETARGET_USART       1  // vs RETARGET_LEUART

#define RETARGET_PERIPHERAL_ENABLE()

#endif//RETARGETSERIALCONFIG_H_
