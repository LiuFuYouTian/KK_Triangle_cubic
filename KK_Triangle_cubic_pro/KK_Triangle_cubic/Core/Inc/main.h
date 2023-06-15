/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define M2_STOP_3V3_Pin GPIO_PIN_13
#define M2_STOP_3V3_GPIO_Port GPIOC
#define M1_DIR_3V3_Pin GPIO_PIN_14
#define M1_DIR_3V3_GPIO_Port GPIOC
#define M2_DIR_3V3_Pin GPIO_PIN_15
#define M2_DIR_3V3_GPIO_Port GPIOC
#define MCU_STAT_Pin GPIO_PIN_3
#define MCU_STAT_GPIO_Port GPIOC
#define NRF_NSS_Pin GPIO_PIN_4
#define NRF_NSS_GPIO_Port GPIOA
#define NRF_IRQ_Pin GPIO_PIN_4
#define NRF_IRQ_GPIO_Port GPIOC
#define NRF_IRQ_EXTI_IRQn EXTI4_IRQn
#define NRF_CE_Pin GPIO_PIN_5
#define NRF_CE_GPIO_Port GPIOC
#define MPU6050_INT_Pin GPIO_PIN_2
#define MPU6050_INT_GPIO_Port GPIOB
#define MPU6050_INT_EXTI_IRQn EXTI2_IRQn
#define KEY4_Pin GPIO_PIN_12
#define KEY4_GPIO_Port GPIOB
#define KEY4_EXTI_IRQn EXTI15_10_IRQn
#define KEY1_Pin GPIO_PIN_6
#define KEY1_GPIO_Port GPIOC
#define KEY1_EXTI_IRQn EXTI9_5_IRQn
#define KEY2_Pin GPIO_PIN_7
#define KEY2_GPIO_Port GPIOC
#define KEY2_EXTI_IRQn EXTI9_5_IRQn
#define DC_BIN1_Pin GPIO_PIN_8
#define DC_BIN1_GPIO_Port GPIOC
#define DC_BIN2_Pin GPIO_PIN_9
#define DC_BIN2_GPIO_Port GPIOC
#define KEY3_Pin GPIO_PIN_15
#define KEY3_GPIO_Port GPIOA
#define KEY3_EXTI_IRQn EXTI15_10_IRQn
#define M1_STOP_3V3_Pin GPIO_PIN_12
#define M1_STOP_3V3_GPIO_Port GPIOC
#define DC_AIN1_Pin GPIO_PIN_2
#define DC_AIN1_GPIO_Port GPIOD
#define DC_AIN2_Pin GPIO_PIN_3
#define DC_AIN2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
