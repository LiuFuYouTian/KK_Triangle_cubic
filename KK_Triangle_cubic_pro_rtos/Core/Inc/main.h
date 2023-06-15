/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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
#define M1_DIR_3V3_Pin GPIO_PIN_13
#define M1_DIR_3V3_GPIO_Port GPIOC
#define M2_DIR_3V3_Pin GPIO_PIN_14
#define M2_DIR_3V3_GPIO_Port GPIOC
#define M1_STOP_3V3_Pin GPIO_PIN_15
#define M1_STOP_3V3_GPIO_Port GPIOC
#define M2_STOP_3V3_Pin GPIO_PIN_0
#define M2_STOP_3V3_GPIO_Port GPIOH
#define MCU_STAT_LED_Pin GPIO_PIN_1
#define MCU_STAT_LED_GPIO_Port GPIOH
#define M1_A_3V3_Pin GPIO_PIN_0
#define M1_A_3V3_GPIO_Port GPIOA
#define M1_B_3V3_Pin GPIO_PIN_1
#define M1_B_3V3_GPIO_Port GPIOA
#define M1_PWM_3V3_Pin GPIO_PIN_2
#define M1_PWM_3V3_GPIO_Port GPIOA
#define M2_PWM_3V3_Pin GPIO_PIN_3
#define M2_PWM_3V3_GPIO_Port GPIOA
#define MPU6050_INT_Pin GPIO_PIN_4
#define MPU6050_INT_GPIO_Port GPIOA
#define NRF_IRQ_Pin GPIO_PIN_2
#define NRF_IRQ_GPIO_Port GPIOB
#define OLED_SCL_Pin GPIO_PIN_10
#define OLED_SCL_GPIO_Port GPIOB
#define NRF_CE_Pin GPIO_PIN_12
#define NRF_CE_GPIO_Port GPIOB
#define NRF_NSS_Pin GPIO_PIN_8
#define NRF_NSS_GPIO_Port GPIOA
#define OLED_SDA_Pin GPIO_PIN_3
#define OLED_SDA_GPIO_Port GPIOB
#define RGB_3V3_Pin GPIO_PIN_5
#define RGB_3V3_GPIO_Port GPIOB
#define M2_A_3V3_Pin GPIO_PIN_6
#define M2_A_3V3_GPIO_Port GPIOB
#define M2_B_3V3_Pin GPIO_PIN_7
#define M2_B_3V3_GPIO_Port GPIOB
#define MPU6050_SCL_Pin GPIO_PIN_8
#define MPU6050_SCL_GPIO_Port GPIOB
#define MPU6050_SDA_Pin GPIO_PIN_9
#define MPU6050_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
