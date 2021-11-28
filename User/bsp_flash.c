#include "stm32f10x.h"
#include "bsp_flash.h"

uint16_t STMFLASH_ReadHalfWord(uint32_t faddr){
    return *(int16_t *)faddr;
}
#if STM32_FLASH_WREN

void STMFLASH_Write(uint32_t WriteAddr, uint16_t *pBuffer, uint16_t NumToWrite) {
    uint32_t EraseCounter = 0x00; 
	uint32_t Address = 0x00;
	uint32_t NbrOfPage = 0x00;
    uint16_t i = 0;
	FLASH_Status FLASHStatus = FLASH_COMPLETE;
	
    if (WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))
        return;
    FLASH_Unlock();    
    NbrOfPage = NumToWrite / FLASH_PAGE_SIZE + 1;
		FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
    for(EraseCounter = 0; (EraseCounter < NbrOfPage)&&(FLASHStatus == FLASH_COMPLETE); EraseCounter++) {
		FLASHStatus = FLASH_ErasePage(WriteAddr + (FLASH_PAGE_SIZE * EraseCounter));
	}
    Address = WriteAddr;
	while ((Address < WriteAddr + NumToWrite * 2) && (i < NumToWrite) && (FLASHStatus == FLASH_COMPLETE)) {
		FLASHStatus = FLASH_ProgramHalfWord(Address, pBuffer[i]);
		Address += 2;
        i++;
	}
    FLASH_Lock();
}
#endif

void STMFLASH_Read(uint32_t ReadAddr, uint16_t *pBuffer, uint16_t NumToRead){
    uint16_t i = 0;
    for (i = 0; i < NumToRead; i++){
        pBuffer[i] = STMFLASH_ReadHalfWord(ReadAddr);
        ReadAddr += 2;
    }
}
