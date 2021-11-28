#include "stm32f10x.h"
#include "bsp_led.h"

void LED_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(LED_CLK, ENABLE);
    //RED
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Pin = LED_RED_PIN;
    GPIO_Init(LED_RED_PORT, &GPIO_InitStruct);

    //GREEN
    GPIO_InitStruct.GPIO_Pin = LED_GREEN_PIN;
    GPIO_Init(LED_GREEN_PORT, &GPIO_InitStruct);

    //BLUE
    GPIO_InitStruct.GPIO_Pin = LED_BLUE_PIN;
    GPIO_Init(LED_BLUE_PORT, &GPIO_InitStruct);

    LED_BLUE_OFF;
    LED_RED_OFF;
    LED_GREEN_OFF;
}

