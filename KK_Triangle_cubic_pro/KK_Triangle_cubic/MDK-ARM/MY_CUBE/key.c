#include "key.h"
#include "tim.h"
#include "main.h"
#include "stdio.h"

uint16_t key_flag = 0;

void KEY_Handler(void)//�����жϴ�������δʹ��
{
	switch(key_flag)
	{
		case KEY1_Pin:		printf("KEY1_Pin\r\n");
		
		break;
		
		case KEY2_Pin: printf("KEY2_Pin\r\n");

		break;
		
		case KEY3_Pin: printf("KEY3_Pin\r\n");

		break;
		
		case KEY4_Pin:		printf("KEY4_Pin\r\n");

		break;
	}
	key_flag = 0;
}
