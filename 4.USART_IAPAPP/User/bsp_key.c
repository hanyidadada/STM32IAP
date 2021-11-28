#include "stm32f10x.h"
#include "bsp_key.h"

static void NVIC_Configuration(void) {
		NVIC_InitTypeDef NVIC_InitStruct;
		
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
		NVIC_InitStruct.NVIC_IRQChannel = KEY1_IRQ;
		NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
		NVIC_Init(&NVIC_InitStruct);
		
		NVIC_InitStruct.NVIC_IRQChannel = KEY2_IRQ;
		NVIC_Init(&NVIC_InitStruct);
}

void KEY_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct;
		EXTI_InitTypeDef EXTI_InitStruct;
		NVIC_Configuration();
		// ¿ªÆôAFIO
    RCC_APB2PeriphClockCmd(KEY1_CLK | KEY2_CLK, ENABLE);
    //KEY1
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = KEY1_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(KEY1_PORT, &GPIO_InitStruct);

    //KEY2
    GPIO_InitStruct.GPIO_Pin = KEY2_PIN;
    GPIO_Init(KEY2_PORT, &GPIO_InitStruct);
		
		GPIO_EXTILineConfig(KEY1_PORTSOURCE, KEY1_PINSOURCE);
		EXTI_InitStruct.EXTI_Line = KEY1_LINE;
		EXTI_InitStruct.EXTI_LineCmd = ENABLE;
		EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
		EXTI_Init(&EXTI_InitStruct);
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
