#include "tim.h"
#include "pid.h"
#include "filter.h"
#include "adc.h"
#include "EXTI.h"
#include "stdio.h"
#include "usart.h"
#include "control.h"
#include "mpu_dmp_useapi.h"
#include "Task_dispose.h"
#include "nrf24L01.h"

Moto_Speed_TYPE M1;
Moto_Speed_TYPE M2;

//�ǶȻ�PID 
PID_TYPE PID_ROL_Angle;
PID_TYPE PID_PIT_Angle;
PID_TYPE PID_YAW_Angle;
//���ٶȻ�PID 
PID_TYPE PID_ROL_Rate;
PID_TYPE PID_PIT_Rate;
PID_TYPE PID_YAW_Rate;

//�ٶȻ�PID 
PID_TYPE PID_ROL_Speed;
PID_TYPE PID_PIT_Speed;
PID_TYPE PID_YAW_Speed;
//ת��Ȼ�PID 
PID_TYPE PID_ROLL;



uint8_t Blance_Enable = 0;
float ROL_GYRO = 0;

float Limiting(float DATA,float MIN,float MAX)//��ʵ���޷�
{
	if(MAX<MIN) return DATA;
	DATA = (DATA>=MAX)?MAX:DATA;
	DATA = (DATA<=MIN)?MIN:DATA;
	return DATA;
}

float ABS(float DATA)//��ʵ��ȡ����ֵ
{
	DATA = (DATA >= 0)? DATA:(-DATA);
	return DATA;
}

void Get_CaptureNumber(void)//ͨ���������ӿڻ�ȡ��ǰ���ת��
{
	M1.CaptureNumber_new=__HAL_TIM_GET_COUNTER(&htim2);
	__HAL_TIM_SET_COUNTER(&htim2,30000);
	M1.CaptureNumber_new = M1.CaptureNumber_new - 30000;
	
	M1.CaptureNumber_last *= (1.0 - M1_FILTE);								//===һ�׵�ͨ�˲���
	M1.CaptureNumber_last += M1.CaptureNumber_new*M1_FILTE;	//===һ�׵�ͨ�˲���
	

	M2.CaptureNumber_new =__HAL_TIM_GET_COUNTER(&htim4);
	__HAL_TIM_SET_COUNTER(&htim4,30000);
	M2.CaptureNumber_new  = 30000 - M2.CaptureNumber_new;
	M2.CaptureNumber_last *= (1.0 - M2_FILTE);												//===һ�׵�ͨ�˲���
	M2.CaptureNumber_last += M2.CaptureNumber_new*M2_FILTE; //===һ�׵�ͨ�˲���	
	
//	printf("M1_NEW,M1_LAST:%f,%f\r\n",M1.CaptureNumber_new,M1.CaptureNumber_last);
}


void cubic_control(void)//���PID���㣬���������
{
	dmp_getdata();				//��ȡ��̬����	
	Get_CaptureNumber();  //��ȡ���ת��
	SortAver_Filter(gyro[0],&ROL_GYRO,12);
	PID_Postion_Cal(&PID_ROL_Rate,0,ROL_GYRO);
	PID_ROL_Rate.OutPut = Limiting(PID_ROL_Rate.OutPut,-900,900);
//	printf("PID_ROL_Rate.Dout,gyro[1]:%f,%f\r\n",PID_ROL_Rate.OutPut,ROL_GYRO);
	

//	Set_Pwm(PID_ROL_Rate.OutPut,0);
}


void Set_Pwm(int moto1,int moto2)//����PWMռ�ձ�0~900
{
    	if(moto1>0)	{//�жϵ��ת��
				HAL_GPIO_WritePin(GPIOC, M1_DIR_3V3_Pin, GPIO_PIN_RESET);
			}
			else{
				moto1 = -moto1;
				HAL_GPIO_WritePin(GPIOC, M1_DIR_3V3_Pin, GPIO_PIN_SET); 
			}
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, moto1);//���õ��PWM
			
			
			if(moto2>0)	{	
				HAL_GPIO_WritePin(GPIOC, M2_DIR_3V3_Pin, GPIO_PIN_RESET);
			}
			else{
				moto2 = -moto2;
				HAL_GPIO_WritePin(GPIOC, M2_DIR_3V3_Pin, GPIO_PIN_SET); 
			}
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, moto2);//���õ��PWM
}


