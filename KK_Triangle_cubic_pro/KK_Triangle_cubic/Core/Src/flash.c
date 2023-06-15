/*******************************************************************************************

*******************************************************************************************/
#include "flash.h"
#include "stm32f1xx_hal.h"
#include "stdio.h"

uint32_t FLASH_ErasePage(void)
{
	uint32_t PAGEError = 0;
  FLASH_EraseInitTypeDef EraseInitStruct;
	  /* Fill EraseInit structure*/
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;
  EraseInitStruct.NbPages     = (FLASH_USER_END_ADDR - FLASH_USER_START_ADDR) / FLASH_PAGE_SIZE;

  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
  {
    /*
      Error occurred while page erase.
      User can add here some code to deal with this error.
      PAGEError will contain the faulty page and then to know the code error on this page,
      user can call function 'HAL_FLASH_GetError()'
    */
    /* Infinite loop */
		printf("HAL_FLASHEx_Erase_Error\r\n");
		return HAL_ERROR;
  }
	printf("HAL_FLASHEx_Erase_Succer\r\n");
	return HAL_OK;
}

/******************************************************************************
* 函  数：u32 STMFLASH_ReadWord(u32 faddr)
* 功　能：读取指定地址的字(32位数据) 
* 参  数：faddr:读地址 
* 返回值：对应数据
* 备  注：无
*******************************************************************************/
uint32_t STMFLASH_ReadWord(uint32_t faddr)
{
	return *(__IO uint32_t*)faddr;; 
}  

/******************************************************************************
* 函  数：void STMFLASH_Write(u32 WriteAddr,u32 *pBuffer,u32 NumToWrite)	
* 功　能：从指定地址开始写入指定长度的数据 
* 参  数：WriteAddr:起始地址(此地址必须为4的倍数!!)
*         pBuffer:数据指针
*         NumToWrite:字(32位)数(就是要写入的32位数据的个数.) 
* 返回值：无
* 备  注：STM32F1的Flash未写扇区默认是0xFFF...F
*******************************************************************************/
void STMFLASH_Write(uint32_t WriteAddr,uint32_t *pBuffer,uint32_t NumToWrite)	
{ 
	uint32_t status = HAL_OK;
	uint32_t addrx=0;
	uint32_t endaddr=0;	
//	printf("STMFLASH_Write\r\n");
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+2048*128)))return;	//非法地址
	HAL_FLASH_Unlock();				 //解锁 
 
	addrx=WriteAddr;				 //写入的起始地址
	endaddr=WriteAddr+NumToWrite*4;	 //写入的结束地址
	printf("WriteAddr:%x\r\n",WriteAddr);
//	printf("addrx:%x,%x,%x\r\n",addrx,endaddr,FLASH_USER_END_ADDR);
	if(addrx<FLASH_USER_END_ADDR)			       //只有主存储区,才需要执行擦除操作!!
	{
		while(addrx<endaddr)		       //扫清一切障碍.(对非FFFFFFFF的地方,先擦除)
		{	
			if(STMFLASH_ReadWord(addrx)!=0XFFFFFFFF)//有非0XFFFFFFFF的地方,要擦除这个页
			{   
				status = FLASH_ErasePage();
			}
			else 
			addrx+=4;
		} 
	}
	if(status==HAL_OK)
	{
		while(WriteAddr<endaddr) //写数据
		{

			if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,(uint32_t)WriteAddr,*pBuffer) != HAL_OK)
			{ 
				break; //写入异常
			}
			WriteAddr+=4;
			pBuffer++;
		} 
	}
	
	HAL_FLASH_Lock(); //上锁
} 

/******************************************************************************
* 函  数：void STMFLASH_Read(u32 ReadAddr,u32 *pBuffer,u32 NumToRead)  
* 功　能：从指定地址开始读出指定长度的数据
* 参  数：ReadAddr:起始地址
*         pBuffer:数据指针
*         NumToRead:字(4位)数
* 返回值：无
* 备  注：无
*******************************************************************************/
void STMFLASH_Read(uint32_t ReadAddr,uint32_t *pBuffer,uint32_t NumToRead)   	
{
	uint32_t i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadWord(ReadAddr);//读取4个字节.
		ReadAddr+=4;//偏移4个字节.	
	}
}


