#include "main.h"
#include "OLED.h"
#include "codetab.h"
#include "i2c.h"
/************************************************************************************
*  Copyright (c), 2014, HelTec Automatic Technology co.,LTD.
*            All rights reserved.
*
* Http:    www.heltec.cn
* Email:   cn.heltec@gmail.com
* WebShop: heltec.taobao.com
*
* File name: OLED_I2C.c
* Project  : HelTec.uvprij
* Processor: STM32F103C8T6
* Compiler : MDK fo ARM
* 
* Author : С��
* Version: 1.00
* Date   : 2014.4.8
* Email  : hello14blog@gmail.com
* Modification: none
* 
* Description:128*64�����OLED��ʾ�������ļ����������ڻ����Զ���(heltec.taobao.com)��SD1306����IICͨ�ŷ�ʽ��ʾ��
*
* Others: none;
*
* Function List:
*	1. void I2C_Configuration(void) -- ����CPU��Ӳ��I2C
* 2. void I2C_WriteByte(uint8_t addr,uint8_t data) -- ��Ĵ�����ַдһ��byte������
* 3. void WriteCmd(unsigned char I2C_Command) -- д����
* 4. void WriteDat(unsigned char I2C_Data) -- д����
* 5. void OLED_Init(void) -- OLED����ʼ��
* 6. void OLED_SetPos(unsigned char x, unsigned char y) -- ������ʼ������
* 7. void OLED_Fill(unsigned char fill_Data) -- ȫ�����
* 8. void OLED_CLS(void) -- ����
* 9. void OLED_ON(void) -- ����
* 10. void OLED_OFF(void) -- ˯��
* 11. void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize) -- ��ʾ�ַ���(�����С��6*8��8*16����)
* 12. void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N) -- ��ʾ����(������Ҫ��ȡģ��Ȼ��ŵ�codetab.h��)
* 13. void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]) -- BMPͼƬ
*
* History: none;
*
*************************************************************************************/
extern float pit,rol,yaw;							//��̬��

void OLED_display_init(void)
{
	OLED_Init();
	
	OLED_DrawBMP(0,0,128,8,(unsigned char *)NO_LINK);//����BMPλͼ��ʾ
	rignt_set(5,1);


//	rignt_set(5,0);
//	OLED_CLS();			//����
//	OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//����BMPλͼ��ʾ
//	rignt_set(5,1);
//	HAL_Delay(2000);
//	rignt_set(5,0);
//	OLED_CLS();//����
//	OLED_DrawBMP(0,0,128,6,(unsigned char *)BMP6);
//	rignt_set(0,1);
//	OLED_CLS();//����
//	OLED_ShowStr(0,0,"PIT:",2);				//����8*16�ַ�
//	OLED_ShowStr(0,2,"ROL:",2);				//����8*16�ַ�

//	OLED_ShowStr(0,4,"YAW:",2);				//����8*16�ַ�
//	OLED_ShowStr(0,6,"SPE:",2);				//����8*16�ַ�
	
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//����BMPλͼ��ʾ
//		HAL_Delay(1000);
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//����BMPλͼ��ʾ
//		HAL_Delay(1000);
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP3);//����BMPλͼ��ʾ
//		HAL_Delay(1000);
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP4);//����BMPλͼ��ʾ
//		HAL_Delay(1000);
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//����BMPλͼ��ʾ
}

void oled_display(void)
{
	OLED_ShowNUM(40,0,pit*100,2);				//����8*16�ַ�
	OLED_ShowNUM(40,2,rol*100,2);				//����8*16�ַ�

	OLED_ShowNUM(40,4,yaw*100,2);				//����8*16�ַ�
//	OLED_ShowNUM(40,6,motor1_frequency,2);				//����8*16�ַ�
}

void rignt_set(unsigned char del,unsigned char flag)
{
	unsigned char i;
	if(flag == 0)
	{
		for(i = 0xfe;i > 1;i--)
		{
			WriteCmd(0x81); //--set contrast control register
			WriteCmd(i); //���ȵ��� 0x00~0xff
			HAL_Delay(del);
		}
		WriteCmd(0x81); //--set contrast control register
		WriteCmd(0x00); //���ȵ��� 0x00~0xff
	}
	else
	{
		for(i = 0;i < 0xfe;i++)
		{
			WriteCmd(0x81); //--set contrast control register
			WriteCmd(i); //���ȵ��� 0x00~0xff
			HAL_Delay(del);
		}
		WriteCmd(0x81); //--set contrast control register
		WriteCmd(0xff); //���ȵ��� 0x00~0xff
	}
}
void WriteCmd(unsigned char I2C_Command)//д����
{
	unsigned char data_buff [2] = {0x00,I2C_Command};
	HAL_I2C_Master_Transmit(&hi2c2,OLED_ADDRESS,data_buff,2, 10); 
}

void WriteDat(unsigned char I2C_Data)//д����
{
	unsigned char data_buff [2] = {0x40,I2C_Data};
	HAL_I2C_Master_Transmit(&hi2c2,OLED_ADDRESS,data_buff,2, 10); 
}

void OLED_Init(void)
{
	HAL_Delay(100); //�������ʱ����Ҫ
	
	WriteCmd(0xAE); //display off
	WriteCmd(0x20);	//Set Memory Addressing Mode	
	WriteCmd(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	WriteCmd(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	WriteCmd(0xc0);	//Set COM Output Scan Direction
	WriteCmd(0x00); //---set low column address
	WriteCmd(0x10); //---set high column address
	WriteCmd(0x40); //--set start line address
	WriteCmd(0x81); //--set contrast control register
	WriteCmd(0x00); //���ȵ��� 0x00~0xff
	WriteCmd(0xa0); //--set segment re-map 0 to 127
	WriteCmd(0xa6); //--set normal display(A6h/A7h)
	WriteCmd(0xa8); //--set multiplex ratio(1 to 64)
	WriteCmd(0x3F); //
	WriteCmd(0xa4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	WriteCmd(0xd3); //-set display offset
	WriteCmd(0x00); //-not offset
	WriteCmd(0xd5); //--set display clock divide ratio/oscillator frequency
	WriteCmd(0xf0); //--set divide ratio
	WriteCmd(0xd9); //--set pre-charge period
	WriteCmd(0x22); //
	WriteCmd(0xda); //--set com pins hardware configuration
	WriteCmd(0x12);
	WriteCmd(0xdb); //--set vcomh
	WriteCmd(0x20); //0x20,0.77xVcc
	WriteCmd(0x8d); //--set DC-DC enable
	WriteCmd(0x14); //
	WriteCmd(0xaf); //--turn on oled panel
	OLED_CLS();			//����
}

void OLED_SetPos(unsigned char x, unsigned char y) //������ʼ������
{ 
	WriteCmd(0xb0+y);
	WriteCmd(((x&0xf0)>>4)|0x10);
	WriteCmd((x&0x0f)|0x01);
}

void OLED_Fill(unsigned char fill_Data)//ȫ�����
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		WriteCmd(0xb0+m);		//page0-page1
		WriteCmd(0x00);		//low column start address
		WriteCmd(0x10);		//high column start address
		for(n=0;n<128;n++)
		{
			WriteDat(fill_Data);
		}
	}
}

void OLED_CLS(void)//����
{
	OLED_Fill(0x00);
}

//--------------------------------------------------------------
// Prototype      : void OLED_ON(void)
// Calls          : 
// Parameters     : none
// Description    : ��OLED�������л���
//--------------------------------------------------------------
void OLED_ON(void)
{
	WriteCmd(0X8D);  //���õ�ɱ�
	WriteCmd(0X14);  //������ɱ�
	WriteCmd(0XAF);  //OLED����
}

//--------------------------------------------------------------
// Prototype      : void OLED_OFF(void)
// Calls          : 
// Parameters     : none
// Description    : ��OLED���� -- ����ģʽ��,OLED���Ĳ���10uA
//--------------------------------------------------------------
void OLED_OFF(void)
{
	WriteCmd(0X8D);  //���õ�ɱ�
	WriteCmd(0X10);  //�رյ�ɱ�
	WriteCmd(0XAE);  //OLED����
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowChar(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
// Calls          : 
// Parameters     : x,y -- ��ʼ������(x:0~127, y:0~7); ch[] -- Ҫ��ʾ���ַ���; TextSize -- �ַ���С(1:6*8 ; 2:8*16)
// Description    : ��ʾcodetab.h�е�ASCII�ַ�,��6*8��8*16��ѡ��
//--------------------------------------------------------------
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
{
	unsigned char c = 0,i = 0,j = 0;
	switch(TextSize)
	{
		case 1:
		{
			while(ch[j] != '\0')
			{
				c = ch[j] - 32;
				if(x > 126)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<6;i++)
					WriteDat(F6x8[c][i]);
				x += 6;
				j++;
			}
		}break;
		case 2:
		{
			while(ch[j] != '\0')
			{
				c = ch[j] - 32;
				if(x > 120)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i]);
				OLED_SetPos(x,y+1);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i+8]);
				x += 8;
				j++;
			}
		}break;
	}
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
// Calls          : 
// Parameters     : x,y -- ��ʼ������(x:0~127, y:0~7); N:������codetab.h�е�����
// Description    : ��ʾcodetab.h�еĺ���,16*16����
//--------------------------------------------------------------
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
{
	unsigned char wm=0;
	unsigned int  adder=32*N;
	OLED_SetPos(x , y);
	for(wm = 0;wm < 16;wm++)
	{
		WriteDat(F16x16[adder]);
		adder += 1;
	}
	OLED_SetPos(x,y + 1);
	for(wm = 0;wm < 16;wm++)
	{
		WriteDat(F16x16[adder]);
		adder += 1;
	}
}

//--------------------------------------------------------------
// Prototype      : void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
// Calls          : 
// Parameters     : x0,y0 -- ��ʼ������(x0:0~127, y0:0~7); x1,y1 -- ���Խ���(������)������(x1:1~128,y1:1~8)
// Description    : ��ʾBMPλͼ
//--------------------------------------------------------------
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

  if(y1%8==0)
		y = y1/8;
  else
		y = y1/8 + 1;
	for(y=y0;y<y1;y++)
	{
		OLED_SetPos(x0,y);
    for(x=x0;x<x1;x++)
		{
			WriteDat(BMP[j++]);
		}
	}
}

void OLED_DrawBMP_1LING(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x;
	OLED_SetPos(x0,y0);
  for(x=x0;x<x1;x++)
	{
		WriteDat(BMP[j++]);
	}
}

void OLED_ShowNUM(unsigned char x, unsigned char y,unsigned int num, unsigned char TextSize)
{
	unsigned char c = 0,i = 0,j = 0;
	unsigned char digit[4];
	digit[3] = num%10;
	digit[2] = (num%100)/10;
	digit[1] = (num%1000)/100;
	digit[0] = num/1000;
	switch(TextSize)
	{
		case 1:
		{
			while(j != 4)
			{
				c = digit[j] + 16;
				if(x > 126)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<6;i++)
					WriteDat(F6x8[c][i]);
				x += 6;
				j++;
			}
		}break;
		case 2:
		{
			while(j != 4)
			{
				c = digit[j] + 16;
				if(x > 120)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i]);
				OLED_SetPos(x,y+1);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i+8]);
				x += 8;
				j++;
			}
		}break;
	}
}