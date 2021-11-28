#ifndef __BSP_USART_H
#define __BSP_USART_H
#include <stdio.h>

#define DEBUG_USARTx             USART1
#define DEBUG_USART_BAUDRATE     115200
#define DEBUG_USART_CLK          RCC_APB2Periph_USART1

#define DEBUG_USART_TX_PORT      GPIOA
#define DEBUG_USART_TX_PIN       GPIO_Pin_9
#define DEBUG_USART_TX_CLK       RCC_APB2Periph_GPIOA

#define DEBUG_USART_RX_PORT      GPIOA
#define DEBUG_USART_RX_PIN       GPIO_Pin_10
#define DEBUG_USART_RX_CLK       RCC_APB2Periph_GPIOA

void USART_Config(void);
#endif
