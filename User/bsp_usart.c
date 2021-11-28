#include "stm32f10x.h"
#include "bsp_usart.h"

void USART_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(DEBUG_USART_CLK | DEBUG_USART_TX_CLK | DEBUG_USART_TX_CLK, ENABLE);
    //TX
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = DEBUG_USART_TX_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(DEBUG_USART_TX_PORT, &GPIO_InitStruct);
    //RX
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = DEBUG_USART_RX_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(DEBUG_USART_RX_PORT, &GPIO_InitStruct);

    USART_InitTypeDef USART_InitStruct;

    USART_InitStruct.USART_BaudRate = DEBUG_USART_BAUDRATE;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(DEBUG_USARTx, &USART_InitStruct);

    USART_Cmd(DEBUG_USARTx, ENABLE);
}

int fputc(int ch, FILE *fp) {
    USART_SendData(DEBUG_USARTx, ch);
    while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET){
    }
    return ch;
}

int fgetc(FILE *fp) {
    while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET){
    }
    return (int)(USART_ReceiveData(DEBUG_USARTx));
}
