#ifndef __OLED_H
#define	__OLED_H
#include "main.h"

#define OLED_ADDRESS	0x78 //通过调整0R电阻,屏可以0x78和0x7A两个地址 -- 默认0x78

extern const unsigned char BMP1[];
extern const unsigned char BMP2[];
extern const unsigned char BMP3[];
extern const unsigned char BMP4[];
extern const unsigned char BMP6[];
extern const unsigned char LINK[];
extern const unsigned char BAT0[];
extern const unsigned char BAT1[];
extern const unsigned char BAT2[];
extern const unsigned char BAT3[];
extern const unsigned char BAT4[];
extern const unsigned char BAT5[];
extern const unsigned char BAT6[];
extern const unsigned char BAT_clc[];

extern const unsigned char Cute[];

void I2C_Configuration(void);
void I2C_WriteByte(uint8_t addr,uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteDat(unsigned char I2C_Data);
void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
void OLED_ShowPIN(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_DrawBMP_PIN(unsigned char x,unsigned char y);
void INIT_OLEDdisplay(void);
void OLED_ShowNUM(unsigned char x, unsigned char y,unsigned int num, unsigned char TextSize);
void OLED_display_init(void);
void OLED_DrawBMP_1LING(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char BMP[]);
void rignt_set(unsigned char del,unsigned char flag);

void oled_display(void);
#endif
