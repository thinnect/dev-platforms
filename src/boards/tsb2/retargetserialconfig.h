#pragma once

// Configuration for tsb2

#if defined(LOG_USE_JTAG_UART) // Onboard port shared with JTAG pins

#define RETARGET_UART        USART1
#define RETARGET_IRQ_NAME    USART1_RX_IRQHandler
#define RETARGET_CLK         cmuClock_USART1
#define RETARGET_IRQn        USART1_RX_IRQn
#define RETARGET_TX          USART_Tx
#define RETARGET_RX          USART_Rx
#define RETARGET_UART_INDEX  1
#define RETARGET_TXPORT      gpioPortA
#define RETARGET_TXPIN       2
#define RETARGET_RXPORT      gpioPortA
#define RETARGET_RXPIN       1

#define LOGGER_LDMA_USART1

#elif defined(LOG_USE_EXTERNAL_UART) // First 2 pins in left header

#define RETARGET_UART        USART1
#define RETARGET_IRQ_NAME    USART1_RX_IRQHandler
#define RETARGET_CLK         cmuClock_USART1
#define RETARGET_IRQn        USART1_RX_IRQn
#define RETARGET_TX          USART_Tx
#define RETARGET_RX          USART_Rx
#define RETARGET_UART_INDEX  1
#define RETARGET_TXPORT      gpioPortB
#define RETARGET_TXPIN       1
#define RETARGET_RXPORT      gpioPortB
#define RETARGET_RXPIN       0

#define LOGGER_LDMA_USART1

#else // non-JTAG UART

#define RETARGET_UART        USART2
#define RETARGET_IRQ_NAME    USART2_RX_IRQHandler
#define RETARGET_CLK         cmuClock_USART2
#define RETARGET_IRQn        USART2_RX_IRQn
#define RETARGET_TX          USART_Tx
#define RETARGET_RX          USART_Rx
#define RETARGET_UART_INDEX  2
#define RETARGET_TXPORT      gpioPortC
#define RETARGET_TXPIN       1
#define RETARGET_RXPORT      gpioPortC
#define RETARGET_RXPIN       0

#define LOGGER_LDMA_USART2

#endif // pin selection

#define RETARGET_USART       1  // vs RETARGET_LEUART

#define RETARGET_PERIPHERAL_ENABLE()
