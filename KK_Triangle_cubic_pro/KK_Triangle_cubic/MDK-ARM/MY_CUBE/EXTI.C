#include "main.h"
#include "EXTI.h"
#include "key.h"
#include "usart.h"
#include "tim.h"
#include "stdio.h"
#include "ws2812b.h"
#include "ws2812b_fx.h"
#include "mpu_dmp_useapi.h"
#include "Task_dispose.h"
#include "control.h"
#include "nrf24L01.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) 
{
	if(GPIO_Pin == MPU6050_INT_Pin){//MPU6050中断业务代码
		if(Task.ms5_count++ >= 65500){//利用MPU6050 5ms中断实现计时
			Task.ms5_count = 0;
			Task.ms5 = 0;
			Task.ms50 = 0;
			Task.ms100 = 0;
			Task.ms200 = 0;
			Task.ms1000 = 0;
		}
		cubic_control();//姿态控制全部在此函数内完成
	}
	
	if(GPIO_Pin == NRF_IRQ_Pin) {//NRF_IRQ_Pin业务代码
		CHANNEL.CC_FLAG = 1;       //更新遥控接收标志位，在while轮询中处理接收数据
//		printf("NRF24L01无线模块IQQ\r\n");
	}
	
	if(GPIO_Pin == KEY1_Pin) {//KEY1_Pin业务代码
		key_flag = KEY1_Pin;
	}
	if(GPIO_Pin == KEY2_Pin) {//KEY2_Pin业务代码
		key_flag = KEY2_Pin;
	}
	if(GPIO_Pin == KEY3_Pin) {//KEY3_Pin业务代码
		key_flag = KEY3_Pin;
	}
	if(GPIO_Pin == KEY4_Pin) {//KEY4_Pin业务代码
		key_flag = KEY4_Pin;
	}
}

void HAL_SYSTICK_Callback(void)
{
	WS2812BFX_SysTickCallback();	// FX effects software timers
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//预留调参使用，未实现
{
  if(huart->Instance == USART1)
  {  
    HAL_UART_Receive_IT(&huart1,(uint8_t*) RxBuffer,20);
		for(int16_t i = 0;i <= 9;i++){
			printf("RxBuffer:%d\r\n",RxBuffer[i]);
		}
  }
}
