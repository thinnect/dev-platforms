#pragma once

// Configuration for tsb, best to use the dedicated UART, but when that uart
// is needed for HDLC, then it is possible to use the shared JTAG UART for
// logging, but this tends to create problems with subsequent flashin.
// So a PA0 / PA1 option has also been defined - EXTERNAL UART.

#if defined(LOGGER_LDMA_UART0)

#define RETARGET_UART        USART0
#define RETARGET_IRQ_NAME    USART0_RX_IRQHandler
#define RETARGET_CLK         cmuClock_USART0
#define RETARGET_IRQn        USART0_RX_IRQn
#define RETARGET_TX          USART_Tx
#define RETARGET_RX          USART_Rx
#define RETARGET_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC12
#define RETARGET_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC9
#define RETARGET_USART       1

#elif defined(LOGGER_LDMA_LEUART0)

#define RETARGET_UART        LEUART0
#define RETARGET_IRQ_NAME    LEUART0_IRQHandler
#define RETARGET_CLK         cmuClock_LEUART0
#define RETARGET_IRQn        LEUART0_IRQn
#define RETARGET_TX          LEUART_Tx
#define RETARGET_RX          LEUART_Rx
#define RETARGET_TX_LOCATION _LEUART_ROUTELOC0_TXLOC_LOC12
#define RETARGET_RX_LOCATION _LEUART_ROUTELOC0_RXLOC_LOC9
#define RETARGET_LEUART      1

#endif

#if defined(LOG_USE_JTAG_UART) // Onboard port shared with JTAG pins

#define RETARGET_TXPORT      gpioPortF
#define RETARGET_TXPIN       3
#define RETARGET_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC27
#define RETARGET_RXPORT      gpioPortF
#define RETARGET_RXPIN       0
#define RETARGET_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC23

#elif defined(LOG_USE_EXTERNAL_UART) // First 2 pins in left header

#define RETARGET_TXPORT      gpioPortA
#define RETARGET_TXPIN       0
#define RETARGET_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC0
#define RETARGET_RXPORT      gpioPortA
#define RETARGET_RXPIN       1
#define RETARGET_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC0

#else // Use the non-JTAG uart, works best for logging.

#define RETARGET_TXPORT      gpioPortC
#define RETARGET_TXPIN       7
#define RETARGET_RXPORT      gpioPortB
#define RETARGET_RXPIN       15

#endif // UART/pin selection

#define RETARGET_PERIPHERAL_ENABLE()
