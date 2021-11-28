#ifndef __BSP_IAP_H
#define __BSP_IAP_H
typedef  void (*iapfun)(void);

#define FLASH_APP1_ADDR		0x08010000 

void IAP_WRITEAPP2FLASH(uint32_t APP_addr, uint8_t *data, uint16_t datalen);
void IAP_LoadAPP(uint32_t APP_addr);
#endif
