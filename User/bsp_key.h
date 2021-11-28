#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#define KEY1_PORT       GPIOA
#define KEY1_PIN        GPIO_Pin_0
#define KEY1_CLK        RCC_APB2Periph_GPIOA

#define KEY2_PORT       GPIOC
#define KEY2_PIN        GPIO_Pin_13
#define KEY2_CLK        RCC_APB2Periph_GPIOC
#define KEY_ON          1

typedef enum{
    KEY_OFF = 0,
    KEY1_ON,
    KEY2_ON,
}KEY_ENUM;

uint32_t KEY_SCAN(void);
void KEY_Config(void);
#endif
