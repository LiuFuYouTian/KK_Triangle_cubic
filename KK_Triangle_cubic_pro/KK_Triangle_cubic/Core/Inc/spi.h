/**
  ******************************************************************************
  * File Name          : SPI.h
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __spi_H
#define __spi_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN Private defines */
#define u8 uint8_t
#define u16 uint16_t
#define vu8 uint8_t

#define CE_LOW					HAL_GPIO_WritePin(NRF_CE_GPIO_Port,NRF_CE_Pin,GPIO_PIN_RESET);
#define CE_HIGH					HAL_GPIO_WritePin(NRF_CE_GPIO_Port,NRF_CE_Pin,GPIO_PIN_SET);

#define CSN_LOW					HAL_GPIO_WritePin(NRF_NSS_GPIO_Port,NRF_NSS_Pin,GPIO_PIN_RESET);
#define CSN_HIGH				HAL_GPIO_WritePin(NRF_NSS_GPIO_Port,NRF_NSS_Pin,GPIO_PIN_SET);
/* USER CODE END Private defines */

void MX_SPI1_Init(void);
void MX_SPI2_Init(void);

/* USER CODE BEGIN Prototypes */


u8 SPI_Read_Buf(u8 reg, u8 *pBuf, u8 len);
u8 SPI_Write_Buf(u8 reg, u8 *pBuf, u8 len);
u8 SPI_Read_Byte(u8 reg);
uint8_t SPI_Write_Byte(uint8_t reg, uint8_t value);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ spi_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
