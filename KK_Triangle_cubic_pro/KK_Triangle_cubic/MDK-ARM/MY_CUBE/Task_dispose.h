#ifndef Task_dispose_H_
#define Task_dispose_H_

#include "stm32f1xx_hal.h"

//ϵͳʱ������ݽṹ 
typedef struct TIME
{
  uint8_t S;    //��	
	uint8_t M;    //��	
	uint8_t H;    //��	
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
