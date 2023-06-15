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
	if(GPIO_Pin == MPU6050_INT_Pin){//MPU6050�ж�ҵ�����
		if(Task.ms5_count++ >= 65500){//����MPU6050 5ms�ж�ʵ�ּ�ʱ
			Task.ms5_count = 0;
			Task.ms5 = 0;
			Task.ms50 = 0;
			Task.ms100 = 0;
			Task.ms200 = 0;
			Task.ms1000 = 0;
		}
		cubic_control();//��̬����ȫ���ڴ˺��������
	}
	
	if(GPIO_Pin == NRF_IRQ_Pin) {//NRF_IRQ_Pinҵ�����
		CHANNEL.CC_FLAG = 1;       //����ң�ؽ��ձ�־λ����while��ѯ�д�����������
//		printf("NRF24L01����ģ��IQQ\r\n");
	}
	
	if(GPIO_Pin == KEY1_Pin) {//KEY1_Pinҵ�����
		key_flag = KEY1_Pin;
	}
	if(GPIO_Pin == KEY2_Pin) {//KEY2_Pinҵ�����
		key_flag = KEY2_Pin;
	}
	if(GPIO_Pin == KEY3_Pin) {//KEY3_Pinҵ�����
		key_flag = KEY3_Pin;
	}
	if(GPIO_Pin == KEY4_Pin) {//KEY4_Pinҵ�����
		key_flag = KEY4_Pin;
	}
}

void HAL_SYSTICK_Callback(void)
{
	WS2812BFX_SysTickCallback();	// FX effects software timers
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//Ԥ������ʹ�ã�δʵ��
{
  if(huart->Instance == USART1)
  {  
    HAL_UART_Receive_IT(&huart1,(uint8_t*) RxBuffer,20);
		for(int16_t i = 0;i <= 9;i++){
			printf("RxBuffer:%d\r\n",RxBuffer[i]);
		}
  }
}