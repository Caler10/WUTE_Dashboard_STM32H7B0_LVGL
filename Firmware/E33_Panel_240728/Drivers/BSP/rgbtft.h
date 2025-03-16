
#ifndef __RGBTFT_H__
#define __RGBTFT_H__

#include "main.h"

extern LTDC_HandleTypeDef hltdc;


#define HBP  80	// 根据屏幕的手册进行设置
#define VBP  40
#define HSW  1
#define VSW  1
#define HFP  200
#define VFP  22
#define LCD_Width     	800				//	LCD的像素长度
#define LCD_Height    	480				//	LCD的像素宽度
#define LCD_MemoryAdd 0x24000000

void RGBTFT_Backlight_Open();
void LCD_PwmSetPulse (uint8_t pulse);	 //设置占空比

void RGBTFT_Clear(uint16_t color);
void RGBTFT_Drawpoint(uint8_t x,uint8_t y);
void RGBTFT_Drawblock(uint16_t wide,uint16_t color);
void RGBTFT_CopyBuffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height,uint32_t *color);
void GUI_DrawPoint(uint16_t x,uint16_t y,uint32_t *color);

#endif