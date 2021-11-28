#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "stm32f10x.h"

#define LED_BLUE_PORT    GPIOB
#define LED_BLUE_CLK		 RCC_APB2Periph_GPIOB
#define LED_BLUE_PIN     GPIO_Pin_1

#define LED_RED_PORT     GPIOB
#define LED_RED_CLK		   RCC_APB2Periph_GPIOB
#define LED_RED_PIN      GPIO_Pin_5

#define LED_GREEN_PORT   GPIOB
#define LED_GREEN_CLK		 RCC_APB2Periph_GPIOB
#define LED_GREEN_PIN    GPIO_Pin_0

#define digitalHi(p,i)  {p->BSRR = i;}
#define digitalLo(p,i) {p->BRR = i;}
#define digitalToggle(p,i)  {p->ODR ^= i;}

#define LED_RED_TOGGLE    digitalToggle(LED_RED_PORT,LED_RED_PIN);
#define LED_RED_OFF    digitalHi(LED_RED_PORT,LED_RED_PIN);
#define LED_RED_ON    digitalLo(LED_RED_PORT,LED_RED_PIN);

#define LED_GREEN_TOGGLE    digitalToggle(LED_GREEN_PORT,LED_GREEN_PIN);
#define LED_GREEN_OFF    digitalHi(LED_GREEN_PORT,LED_GREEN_PIN);
#define LED_GREEN_ON    digitalLo(LED_GREEN_PORT,LED_GREEN_PIN);

#define LED_BLUE_TOGGLE    digitalToggle(LED_BLUE_PORT,LED_BLUE_PIN);
#define LED_BLUE_OFF    digitalHi(LED_BLUE_PORT,LED_BLUE_PIN);
#define LED_BLUE_ON    digitalLo(LED_BLUE_PORT,LED_BLUE_PIN);

#define LED_RED \
									LED_RED_ON; \
									LED_GREEN_OFF; \
									LED_BLUE_OFF;

#define LED_GREEN \
									LED_RED_OFF; \
									LED_GREEN_ON; \
									LED_BLUE_OFF;

#define LED_BLUE \
									LED_RED_OFF; \
									LED_GREEN_OFF; \
									LED_BLUE_ON;

#define LED_YELLOW \
									LED_RED_ON; \
									LED_GREEN_ON; \
									LED_BLUE_OFF;
									
#define LED_PURPLE \
									LED_RED_ON; \
									LED_GREEN_OFF; \
									LED_BLUE_ON;

#define LED_CYAN \
									LED_RED_OFF; \
									LED_GREEN_ON; \
									LED_BLUE_ON;

#define LED_WHITE \
									LED_RED_ON; \
									LED_GREEN_ON; \
									LED_BLUE_ON;

#define LED_RGBOFF \
									LED_RED_OFF; \
									LED_GREEN_OFF; \
									LED_BLUE_OFF;
void init_led(void);

#endif
