#ifndef __CONTROL_H
#define	__CONTROL_H
#include "main.h"
#include "pid.h"

#define M1_FILTE 0.08
#define M2_FILTE 0.08

extern uint8_t Blance_Enable;


//角度环PID 
extern PID_TYPE PID_ROL_Angle;
extern PID_TYPE PID_PIT_Angle;
extern PID_TYPE PID_YAW_Angle;
 //角速度环PID 
extern PID_TYPE PID_ROL_Rate;
extern PID_TYPE PID_PIT_Rate;
extern PID_TYPE PID_YAW_Rate;
 
 //速度环PID 
extern PID_TYPE PID_ROL_Speed;
extern PID_TYPE PID_PIT_Speed;
extern PID_TYPE PID_YAW_Speed;
 //转向环PID 
extern PID_TYPE PID_ROLL;

//电机速度
typedef struct Moto_Speed
{
	float CaptureNumber_new;
	float CaptureNumber_last;
}Moto_Speed_TYPE;  


void cubic_control(void);//完成PID计算，及电机控制
void Set_Pwm(int moto1,int moto2);//设置PWM占空比0~900
void PID_Param_Init(void);
float Limiting(float DATA,float MIN,float MAX);
float ABS(float DATA);

	
#endif
