#include "stm32f10x.h"
#include "bsp_usart.h"

static void NVIC_Configuration(void) {
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_Init(&NVIC_InitStruct);
}

void usart_init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	
	DEBUG_USART_CLKcmd(DEBUG_USART_CLK, ENABLE);
	DEBUG_USART_GPIO_CLKcmd(DEBUG_USART_RX_CLK | DEBUG_USART_TX_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = DEBUG_USART_TX_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = DEBUG_USART_RX_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_RX_PORT, &GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate = DEBUG_USART_BOUNDRATE;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(DEBUG_USARTx, &USART_InitStruct);
	
	NVIC_Configuration();
	USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE); //打开接收中断
	USART_Cmd(DEBUG_USARTx, ENABLE);
}

void USART_SendByte(USART_TypeDef *pUSARTx, uint8_t ch) {
	USART_SendData(pUSARTx, ch);
	while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE)==RESET);
}

void USART_SendString(USART_TypeDef *pUSARTx, char *str) {
	unsigned int k = 0;
	do {
		USART_SendByte(pUSARTx, *(str + k));
		k++;
	}while(*(str + k) != '\0');
	while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}

int fputc(int ch, FILE* fp){
	USART_SendData(DEBUG_USARTx, ch);

	while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);
	return ch;
}

int fgetc(FILE* fp){
	while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

	return (int)USART_ReceiveData(DEBUG_USARTx);
}
