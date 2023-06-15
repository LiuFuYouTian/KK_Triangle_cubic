/*******************************************************************************************

*******************************************************************************************/
#include "pid.h"
#include "control.h"

/*****************************************************************************
* 函  数：void PID_Postion_Cal(PID_TYPE*PID,float target,float measure)
* 功  能：位置式PID算法
* 参  数：PID: 算法P I D参数的结构体
*         target: 目标值
*         measure: 测量值 
* 返回值：无 
* 备  注: 角度环和角速度环共用此函数
*****************************************************************************/
void PID_Postion_Cal(PID_TYPE*PID,float target,float measure)
{
	
	PID->Error  = target - measure;              //误差
	PID->Differ = PID->Error - PID->PreError;    //微分量
	
	PID->Pout = PID->P * PID->Error;                        //比例控制
	PID->Iout = PID->Ilimit_flag * PID->I * PID->Integral;  //积分控制
	PID->Dout = PID->D * PID->Differ;                       //微分控制
	
	PID->OutPut =  PID->Pout + PID->Iout + PID->Dout;       //比例 + 积分 + 微分总控制
//	printf("Pout,Iout,Dout:%f,%f,%f\r\n",PID->Pout,PID->Iout,PID->Dout);
	
	if(Blance_Enable == 1)    //平衡车解锁之后再加入积分,防止积分过调
	{
		if(measure > (PID->Ilimit)||measure < -PID->Ilimit)   //积分分离
		{PID->Ilimit_flag = 0;}
		else
		{
			PID->Ilimit_flag = 1;                               //加入积分(只有测量值在-PID->Ilimit~PID->Ilimit 范围内时才加入积分)
			PID->Integral += PID->Error;                        //对误差进行积分
			if(PID->Integral > PID->Irang)                      //积分限幅
				PID->Integral = PID->Irang;
			if(PID->Integral < -PID->Irang)                     //积分限幅
			    PID->Integral = -PID->Irang;                    
		}
	}else
	{PID->Integral = 0;}
	PID->PreError = PID->Error ;                            //前一个误差值
}


