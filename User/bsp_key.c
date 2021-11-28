#include "stm32f10x.h"
#include "bsp_key.h"

void KEY_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(KEY1_CLK | KEY2_CLK, ENABLE);
    //KEY1
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = KEY1_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY1_PORT, &GPIO_InitStruct);

    //KEY2
    GPIO_InitStruct.GPIO_Pin = KEY2_PIN;
    GPIO_Init(KEY2_PORT, &GPIO_InitStruct);
}

uint32_t KEY_SCAN(void){
    if (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == KEY_ON) {
        while (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == KEY_ON){
        }
        return KEY1_ON;
    }
    if (GPIO_ReadInputDataBit(KEY2_PORT, KEY2_PIN) == KEY_ON) {
        while (GPIO_ReadInputDataBit(KEY2_PORT, KEY2_PIN) == KEY_ON){
        }
        return KEY2_ON;
    }
    return KEY_OFF;
}
