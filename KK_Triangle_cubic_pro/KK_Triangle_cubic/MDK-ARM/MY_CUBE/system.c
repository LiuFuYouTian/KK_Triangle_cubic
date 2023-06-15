#include "system.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "OLED.h"
#include "stdio.h"
#include "mpu_dmp_useapi.h"
#include "paramsave.h"
#include "ws2812b.h"
#include "ws2812b_fx.h"
#include "system.h"
#include "control.h"
#include "adc.h"
#include "nrf24L01.h"

void system_init(void)
{
	PID_ReadFlash();
	HAL_Delay(1000);//上电等待MPU6050稳定
	mpu_dmp_init(); //MPU6050初始

	HAL_UART_Receive_IT(&huart1, (uint8_t*)RxBuffer,20);																//串口接收中断初始（未使用）
	HAL_GPIO_WritePin(GPIOA, M1_STOP_3V3_Pin|M2_STOP_3V3_Pin, GPIO_PIN_RESET);//上电强制关闭电机
	
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);

//	NRF24L01_Check();   //检测NRF24L01是否存在
//	NRF24L01_RX_Mode(); //NRF24L01配置为接收模式，随时接收遥控数据
	
//  WS2812B三色灯FX库
//	WS2812B_Init(&hspi2);
//	WS2812BFX_Init(1);  // Start 1 segment
//	WS2812BFX_SetSpeed(0, 500); // Speed of segment 0
//	WS2812BFX_SetColorRGB(0, 0,0,20);   // Set color 0
//	WS2812BFX_SetMode(0, FX_MODE_COMET);    // Set mode segment 0
//	WS2812BFX_Start(0); // Start segment 

//	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, 120);//电池电压采集开始
//	OLED_display_init();																	//OLED显示屏初始化
	printf("Hello wrold!\r\n");
}
