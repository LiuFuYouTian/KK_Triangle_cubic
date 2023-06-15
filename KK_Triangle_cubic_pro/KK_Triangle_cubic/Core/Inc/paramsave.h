#ifndef   _MONI_FLASH_H
#define   _MONI_FLASH_H
#include "stm32f1xx_hal.h"
//保存的参数数据结构 
typedef struct PIDSave
{
	//角度环 
	uint16_t  ROL_Angle_P;
	uint16_t  ROL_Angle_I;
	uint16_t  ROL_Angle_D;
	uint16_t  PIT_Angle_P;
	uint16_t  PIT_Angle_I;
	uint16_t  PIT_Angle_D;
	uint16_t  YAW_Angle_P;
	uint16_t  YAW_Angle_I;
	uint16_t  YAW_Angle_D;
	//角速度环 
	uint16_t  ROL_Rate_P;
	uint16_t  ROL_Rate_I;
	uint16_t  ROL_Rate_D;
	uint16_t  PIT_Rate_P;
	uint16_t  PIT_Rate_I;
	uint16_t  PIT_Rate_D;
	uint16_t  YAW_Rate_P;
	uint16_t  YAW_Rate_I;
	uint16_t  YAW_Rate_D;
	//速度环
	uint16_t  ROL_Speed_P;
	uint16_t  ROL_Speed_I;
	uint16_t  ROL_Speed_D;
	uint16_t  PIT_Speed_P;
	uint16_t  PIT_Speed_I;
	uint16_t  PIT_Speed_D;
	uint16_t  YAW_Speed_P;
	uint16_t  YAW_Speed_I;
	uint16_t  YAW_Speed_D;
	//转向环
	uint16_t  ROLL_P;
	uint16_t  ROLL_I;
	uint16_t  ROLL_D;
	//电池校准数据
	uint16_t  Battery_S1_Correct;
	uint16_t  Battery_S2_Correct;
	uint16_t  Battery_S3_Correct;

	uint16_t  SI24R1addr;
}PID_SAVE;

void TableToParams(void);
void ParamsToTable(void);
void ParamsClearAll(void);
void PID_WriteFlash(void);
void PID_ReadFlash(void);
void PID_ClearFlash(void);
void DefaultParams(void);
void DefaultParams_WriteFlash(void);
#endif
