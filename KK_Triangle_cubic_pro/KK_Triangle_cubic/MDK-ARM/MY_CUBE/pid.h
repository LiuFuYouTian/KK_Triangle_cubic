#ifndef   _PID_H_
#define   _PID_H_

#include "stm32f1xx_hal.h"
#include "stdio.h"

//PID算法的数据结构 
typedef struct PID
{
  float P;         //参数
  float I;
  float D;
  float Error;     //比例项
  float Integral;  //积分项
  float Differ;    //微分项
  float PreError;
  float PrePreError;
  float Ilimit; 
  float Irang;
  float Pout;
  float Iout;
  float Dout;
  float OutPut;   
  uint8_t Ilimit_flag;    //积分分离	
}PID_TYPE;  

void PID_Postion_Cal(PID_TYPE*PID,float target,float measure);
void UnControl_Check(void);
#endif
