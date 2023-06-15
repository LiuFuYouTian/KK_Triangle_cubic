#ifndef Task_dispose_H_
#define Task_dispose_H_

#include "stm32f1xx_hal.h"

//系统时间的数据结构 
typedef struct TIME
{
  uint8_t S;    //秒	
	uint8_t M;    //秒	
	uint8_t H;    //秒	
}TIME_TYPE;  

typedef struct Task_Flag
{
	uint16_t ms5;
	uint16_t ms50;
	uint16_t ms100;
	uint16_t ms200;
	uint16_t ms1000;
	uint16_t ms5_count;
}Task_Flag_TYPE; 


extern TIME_TYPE TIME;
extern Task_Flag_TYPE Task;

void Task_polling(void);

#endif /* EXTI_H_ */
