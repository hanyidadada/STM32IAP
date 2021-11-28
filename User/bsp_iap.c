#include "stm32f10x.h"
#include "bsp_flash.h"
#include "bsp_iap.h"
#include "stdio.h"

uint16_t iapbuf[1024];

void IAP_WRITEAPP2FLASH(uint32_t APP_addr, uint8_t *data, uint16_t datalen) {
    uint16_t i, t = 0;
    uint16_t temp;
    uint32_t fwaddr = APP_addr;
    for (i = 0; i < datalen; i++)
    {
        temp = data[1] << 8;
        temp += data[0];
        data += 2;
        iapbuf[t++]=temp;
        if (t == 1024) {
            t = 0;
            STMFLASH_Write(fwaddr, iapbuf, 1024);	
			fwaddr+=2048;//偏移2048
        }
    }
    if (t) {
        STMFLASH_Write(fwaddr, iapbuf, t);
    }
}

void IAP_LoadAPP(uint32_t APP_addr) {
    if (((*(int32_t *)APP_addr)&0x2FFE0000) == 0x20000000) {
        iapfun jump;
        jump = (iapfun) *(int32_t *)(APP_addr+4);
        jump();
    } else {
        printf("无可用程序!\n");
    }
    
}
