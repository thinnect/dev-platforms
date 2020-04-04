/**
 * Custom retargetserial for BRD4180A.
 *
 * Don't define HAL_CONFIG or HAL_VCOM_ENABLE, otherwise this configuration
 * will not be used.
 *
 * Copyright Thinnect Inc. 2020
 * @license MIT
 */
#ifndef RETARGETSERIALCONFIG_H
#define RETARGETSERIALCONFIG_H

#include "bsp.h"

#if defined(LOG_USE_EXTERNAL_UART)
	#define RETARGET_IRQ_NAME    USART1_RX_IRQHandler
	#define RETARGET_CLK         cmuClock_USART1
	#define RETARGET_IRQn        USART1_RX_IRQn
	#define RETARGET_UART        USART1
	#define RETARGET_UART_INDEX  1
	#define RETARGET_TX          USART_Tx
	#define RETARGET_RX          USART_Rx
	#define RETARGET_TXPORT      gpioPortB
	#define RETARGET_TXPIN       0
	#define RETARGET_RXPORT      gpioPortB
	#define RETARGET_RXPIN       1
	#define RETARGET_USART       1
#else
	#define RETARGET_IRQ_NAME    USART0_RX_IRQHandler
	#define RETARGET_CLK         cmuClock_USART0
	#define RETARGET_IRQn        USART0_RX_IRQn
	#define RETARGET_UART        USART0
	#define RETARGET_UART_INDEX  0
	#define RETARGET_TX          USART_Tx
	#define RETARGET_RX          USART_Rx
	#define RETARGET_TXPORT      gpioPortA
	#define RETARGET_TXPIN       5
	#define RETARGET_RXPORT      gpioPortA
	#define RETARGET_RXPIN       6
	#define RETARGET_USART       1
#endif

#if defined(RETARGET_VCOM)
  #define RETARGET_PERIPHERAL_ENABLE() \
  GPIO_PinModeSet(BSP_BCC_ENABLE_PORT, BSP_BCC_ENABLE_PIN, gpioModePushPull, 1);
#else
  #define RETARGET_PERIPHERAL_ENABLE()
#endif

#endif//RETARGETSERIALCONFIG_H
