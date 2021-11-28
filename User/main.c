#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_usart.h"
#include "bsp_flash.h"
#include "bsp_iap.h"

uint8_t buff[55*1024] __attribute__ ((at(0X20001000)));
void Delay(__IO u32 nCount); 
int main(void)
{
	int len;
	uint16_t i;
	/* LED 端口初始化 */
	LED_Config();	 
	LED_BLUE_ON;
	/* 初始化串口 */
	USART_Config();
	KEY_Config();
	printf("这是iapbootloader代码，请按下key进行操作!\n");
	while (1) {
		switch (KEY_SCAN()) {
		case 0:
			break;
		case 1:
			printf("请输入bin长度:\n");
		  len = 0;
			len = getchar() << 8;
			len += getchar();
		  printf("目标app长度为0x%x\n", len);
			for (i =0; i < len; i++) {
				buff[i] = getchar();
			}
			IAP_WRITEAPP2FLASH(FLASH_APP1_ADDR, buff, len);
			printf("接收完毕，可以进行跳转执行app，请按下KEY2\n");
			break;
		case 2:
			printf("开始执行目标APP代码!\n");
			IAP_LoadAPP(FLASH_APP1_ADDR);
			break;
		default:
			break;
		}
	}
	
//	if (Internal_FlashTest() == 0) {
//		LED_GREEN_ON;
//	} else {
//		LED_RED_ON;
//	}
}


void Delay(__IO uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}
