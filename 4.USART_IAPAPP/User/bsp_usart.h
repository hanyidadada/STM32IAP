#ifndef __BSP_USART_H
#define __BSP_USART_H
#include <stdio.h>
#define USART_ECO 1

#define DEBUG_USARTx					USART1
#define DEBUG_USART_CLK       RCC_APB2Periph_USART1
#define DEBUG_USART_CLKcmd    RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_PORT   GPIOA
#define DEBUG_USART_TX_PIN    GPIO_Pin_9
#define DEBUG_USART_TX_CLK    (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_RX_PORT   GPIOA
#define DEBUG_USART_RX_PIN		GPIO_Pin_10
#define DEBUG_USART_RX_CLK    (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_CLKcmd  RCC_APB2PeriphClockCmd
#define DEBUG_USART_BOUNDRATE  115200

void usart_init(void);
void USART_SendByte(USART_TypeDef *pUSARTx, uint8_t ch);
void USART_SendString(USART_TypeDef *pUSARTx, char *str);
#endif
