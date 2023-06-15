#ifndef __CONTROL_H
#define	__CONTROL_H
#include "main.h"
#include "pid.h"

#define M1_FILTE 0.08
#define M2_FILTE 0.08

extern uint8_t Blance_Enable;


//�ǶȻ�PID 
extern PID_TYPE PID_ROL_Angle;
extern PID_TYPE PID_PIT_Angle;
extern PID_TYPE PID_YAW_Angle;
 //���ٶȻ�PID 
extern PID_TYPE PID_ROL_Rate;
extern PID_TYPE PID_PIT_Rate;
extern PID_TYPE PID_YAW_Rate;
 
 //�ٶȻ�PID 
extern PID_TYPE PID_ROL_Speed;
extern PID_TYPE PID_PIT_Speed;
extern PID_TYPE PID_YAW_Speed;
 //ת��PID 
extern PID_TYPE PID_ROLL;

//����ٶ�
typedef struct Moto_Speed
{
	float CaptureNumber_new;
	float CaptureNumber_last;
}Moto_Speed_TYPE;  


void cubic_control(void);//���PID���㣬���������
void Set_Pwm(int moto1,int moto2);//����PWMռ�ձ�0~900
void PID_Param_Init(void);
float Limiting(float DATA,float MIN,float MAX);
float ABS(float DATA);

	
#endif
