#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#define KEY1_PORT       GPIOA
#define KEY1_PIN        GPIO_Pin_0
#define KEY1_CLK        (RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO)
#define KEY1_PORTSOURCE  GPIO_PortSourceGPIOA
#define KEY1_PINSOURCE   GPIO_PinSource0
#define KEY1_LINE        EXTI_Line0
#define KEY1_IRQ         EXTI0_IRQn

#define KEY2_PORT       GPIOC
#define KEY2_PIN        GPIO_Pin_13
#define KEY2_CLK        RCC_APB2Periph_GPIOC
#define KEY2_PORTSOURCE  GPIO_PortSourceGPIOA
#define KEY2_PINSOURCE   GPIO_PinSource13
#define KEY2_LINE        EXTI_Line13
#define KEY2_IRQ         EXTI15_10_IRQn

#define KEY_ON          1

typedef enum{
    KEY_OFF = 0,
    KEY1_ON,
    KEY2_ON,
}KEY_ENUM;

uint32_t KEY_SCAN(void);
void KEY_Config(void);
#endif
