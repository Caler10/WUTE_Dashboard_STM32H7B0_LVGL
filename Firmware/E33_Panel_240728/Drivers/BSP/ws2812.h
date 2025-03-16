
#ifndef __WS2812_H
#define __WS2812_H

#include "main.h"

#define Hight_Data            ( 224  )                          //1 ����Լ���ֵ��ռ350
#define Low_Data              ( 112  )                          //0 ����Լ���ֵ,ռ350

#define Reste_Data            ( 50  )                           //80 ��λ��ƽ��Լ���ֵ
#define Led_Num               (  9  )                           //WS2812�Ƹ���
#define Led_Data_Len          ( 24  )                           //WS2812���ݳ��ȣ�������Ҫ24���ֽ�
#define WS2812_Data_Len   (Led_Num * Led_Data_Len)              //ws2812��������Ҫ�����鳤��

//extern uint16_t RGB_buffur[Reste_Data + WS2812_Data_Len];       //���ݻ�������


void WS2812_Display_1(uint32_t Color, uint16_t num);
void WS2812_Display_2( uint8_t red, uint8_t green, uint8_t blue,uint16_t num);

void WS2812_Number_4(uint32_t Color1,uint32_t Color2,uint32_t Color3,uint32_t Color4);//��װ�õ��ĸ��ƺ�����ֻ��Ҫ�ֱ������ĸ��Ƶ���ɫ����
void WS2812_Init(void);
void WS2812_Marquee( uint8_t num );

#endif

