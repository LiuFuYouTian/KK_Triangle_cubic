#ifndef FILTER_H
#define FILTER_H

#include "stm32f1xx_hal.h"

//三轴整型（MPU6050原始数据）
typedef struct
{
	int16_t X;
	int16_t Y;
	int16_t Z;
}INT16_XYZ;

//三轴浮点型
typedef struct
{
	float X;
	float Y;
	float Z;
}FLOAT_XYZ;

float Low_Filter(float value);
void SortAver_Filter(float value,float *filter,uint8_t N);
void  SortAver_Filter1(float value,float *filter,uint8_t n);
void  SortAver_FilterXYZ(INT16_XYZ *acc,FLOAT_XYZ *Acc_filt,uint8_t N);
void Aver_FilterXYZ6(INT16_XYZ *acc,INT16_XYZ *gry,FLOAT_XYZ *Acc_filt,FLOAT_XYZ *Gry_filt,uint8_t N);
void Aver_FilterXYZ(INT16_XYZ *acc,FLOAT_XYZ *Acc_filt,uint8_t N);
void Aver_Filter(float data,float *filt_data,uint8_t n);
void Aver_Filter1(float data,float *filt_data,uint8_t n);
void presssureFilter(float* in, float* out);

void LPF2pSetCutoffFreq_1(float sample_freq, float cutoff_freq);
float LPF2pApply_1(float sample);
#endif
