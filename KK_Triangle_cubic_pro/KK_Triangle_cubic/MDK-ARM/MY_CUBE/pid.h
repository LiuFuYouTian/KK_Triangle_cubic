#ifndef   _PID_H_
#define   _PID_H_

#include "stm32f1xx_hal.h"
#include "stdio.h"

//PID�㷨�����ݽṹ 
typedef struct PID
{
  float P;         //����
  float I;
  float D;
  float Error;     //������
  float Integral;  //������
  float Differ;    //΢����
  float PreError;
  float PrePreError;
  float Ilimit; 
  float Irang;
  float Pout;
  float Iout;
  float Dout;
  float OutPut;   
  uint8_t Ilimit_flag;    //���ַ���	
}PID_TYPE;  

void PID_Postion_Cal(PID_TYPE*PID,float target,float measure);
void UnControl_Check(void);
#endif
