#include "Task_dispose.h"
#include "control.h"
#include "main.h"
#include "adc.h"
#include "key.h"
#include "OLED.h"
#include "stdio.h"
#include "nrf24L01.h"
#include "ws2812b.h"
#include "ws2812b_fx.h"

TIME_TYPE TIME;
Task_Flag_TYPE Task;

void Task_polling(void)
{
//	if(Task.ms5_count - Task.ms5 >= 1){
//		State_control();//״̬���
////		NRF_Transmit();
//		Task.ms5 = Task.ms5_count;
//	}
	
//	if(Task.ms5_count - Task.ms50 >= 10){
//		KEY_Handler();//�������
//		Task.ms50 = Task.ms5_count;
//	}
	
	if(Task.ms5_count - Task.ms100 >= 20){
		HAL_GPIO_TogglePin(MCU_STAT_GPIO_Port,MCU_STAT_Pin);//ָʾ�Ʒ�ת
//		oled_display();	
		Task.ms100 = Task.ms5_count;
		
	}
//	
//	if(Task.ms5_count - Task.ms1000 >= 200){
//		GET_BAT_VOL(); 		 //��ص�ѹ���
//		if(TIME.S++ >= 60){//��ʵ�ּ�ʱ
//			if(TIME.M++ >= 60){
//				TIME.S++;
//			}
//		}
//		Task.ms1000 = Task.ms5_count;
//	}
//	if(CHANNEL.CC_FLAG)
//	{
//		NRF24L01_RxPacket(NRF_RX_BUFF);//����һ�����ݰ�
//		NRF_RX_DIS();									 //���ݰ�����
//		CHANNEL.CC_FLAG = 0;
//	}
}
