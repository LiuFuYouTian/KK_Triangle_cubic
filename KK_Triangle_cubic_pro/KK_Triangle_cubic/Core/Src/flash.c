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
* ��  ����u32 STMFLASH_ReadWord(u32 faddr)
* �����ܣ���ȡָ����ַ����(32λ����) 
* ��  ����faddr:����ַ 
* ����ֵ����Ӧ����
* ��  ע����
*******************************************************************************/
uint32_t STMFLASH_ReadWord(uint32_t faddr)
{
	return *(__IO uint32_t*)faddr;; 
}  

/******************************************************************************
* ��  ����void STMFLASH_Write(u32 WriteAddr,u32 *pBuffer,u32 NumToWrite)	
* �����ܣ���ָ����ַ��ʼд��ָ�����ȵ����� 
* ��  ����WriteAddr:��ʼ��ַ(�˵�ַ����Ϊ4�ı���!!)
*         pBuffer:����ָ��
*         NumToWrite:��(32λ)��(����Ҫд���32λ���ݵĸ���.) 
* ����ֵ����
* ��  ע��STM32F1��Flashδд����Ĭ����0xFFF...F
*******************************************************************************/
void STMFLASH_Write(uint32_t WriteAddr,uint32_t *pBuffer,uint32_t NumToWrite)	
{ 
	uint32_t status = HAL_OK;
	uint32_t addrx=0;
	uint32_t endaddr=0;	
//	printf("STMFLASH_Write\r\n");
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+2048*128)))return;	//�Ƿ���ַ
	HAL_FLASH_Unlock();				 //���� 
 
	addrx=WriteAddr;				 //д�����ʼ��ַ
	endaddr=WriteAddr+NumToWrite*4;	 //д��Ľ�����ַ
	printf("WriteAddr:%x\r\n",WriteAddr);
//	printf("addrx:%x,%x,%x\r\n",addrx,endaddr,FLASH_USER_END_ADDR);
	if(addrx<FLASH_USER_END_ADDR)			       //ֻ�����洢��,����Ҫִ�в�������!!
	{
		while(addrx<endaddr)		       //ɨ��һ���ϰ�.(�Է�FFFFFFFF�ĵط�,�Ȳ���)
		{	
			if(STMFLASH_ReadWord(addrx)!=0XFFFFFFFF)//�з�0XFFFFFFFF�ĵط�,Ҫ�������ҳ
			{   
				status = FLASH_ErasePage();
			}
			else 
			addrx+=4;
		} 
	}
	if(status==HAL_OK)
	{
		while(WriteAddr<endaddr) //д����
		{

			if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,(uint32_t)WriteAddr,*pBuffer) != HAL_OK)
			{ 
				break; //д���쳣
			}
			WriteAddr+=4;
			pBuffer++;
		} 
	}
	
	HAL_FLASH_Lock(); //����
} 

/******************************************************************************
* ��  ����void STMFLASH_Read(u32 ReadAddr,u32 *pBuffer,u32 NumToRead)  
* �����ܣ���ָ����ַ��ʼ����ָ�����ȵ�����
* ��  ����ReadAddr:��ʼ��ַ
*         pBuffer:����ָ��
*         NumToRead:��(4λ)��
* ����ֵ����
* ��  ע����
*******************************************************************************/
void STMFLASH_Read(uint32_t ReadAddr,uint32_t *pBuffer,uint32_t NumToRead)   	
{
	uint32_t i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadWord(ReadAddr);//��ȡ4���ֽ�.
		ReadAddr+=4;//ƫ��4���ֽ�.	
	}
}


