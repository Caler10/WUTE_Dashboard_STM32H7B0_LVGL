
#ifndef __WS2812_H
#define __WS2812_H

#include "main.h"

#define Hight_Data            ( 224  )                          //1 码相对计数值，占350
#define Low_Data              ( 112  )                          //0 码相对计数值,占350

#define Reste_Data            ( 50  )                           //80 复位电平相对计数值
#define Led_Num               (  9  )                           //WS2812灯个数
#define Led_Data_Len          ( 24  )                           //WS2812数据长度，单个需要24个字节
#define WS2812_Data_Len   (Led_Num * Led_Data_Len)              //ws2812级联后需要的数组长度

//extern uint16_t RGB_buffur[Reste_Data + WS2812_Data_Len];       //数据缓存数组


void WS2812_Display_1(uint32_t Color, uint16_t num);
void WS2812_Display_2( uint8_t red, uint8_t green, uint8_t blue,uint16_t num);

void WS2812_Number_4(uint32_t Color1,uint32_t Color2,uint32_t Color3,uint32_t Color4);//封装好的四个灯函数，只需要分别输入四个灯的颜色即可
void WS2812_Init(void);
void WS2812_Marquee( uint8_t num );

#endif

