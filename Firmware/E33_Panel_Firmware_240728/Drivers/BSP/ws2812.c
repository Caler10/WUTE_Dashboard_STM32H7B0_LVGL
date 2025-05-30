//置1使能该驱动库/脚本库
#if 1

/*
该驱动适用于16位自动重载计数器定时器驱动
原TIM3CHANNEL2能驱动（成功例程见IDE）
引脚：PB5 TIM3CH2
*/

/*
点亮过程：
RESET                                        手册知：大于50微秒（设为50PWM计数单位可）
第一个灯RGB数据 00000000 00000000 00000000    数据0：高低电平时间比：8：17
第二个灯RGB数据 00000000 00000000 00000000    数据1：高低电平时间比：16：9
......
*/

#include "myusart.h"
#include "ws2812.h"
#include "main.h"
#include "tim.h"

//数据缓存数组
uint16_t RGB_buffur[Reste_Data + WS2812_Data_Len] = { 0 }; 
//于PWM:每个数存的是每个PWM周期高电平计数值=自动重载值*占空比（so大于0小于自动重载值） 存储格式：16位二进制数

//uint32_t *RGB_Buff_9 = 0x24001000;//第一种尝试
//__align(8) uint8_t value[20] __attribute__((at(0x20000100)));//第二种尝试
__attribute__((section (".RAM_D3"))) uint16_t  RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len];//第三种尝试 全局变量（可在该.c文件中使用）
//好像可以只用声明不用赋0也行

//指定某灯写入缓冲数组函数1
//颜色数据传输格式：RGB888  num：0 1 2 3（灯的位置）
void WS2812_Display_1(uint32_t Color, uint16_t num)
{
    uint16_t* p = (RGB_buffur + Reste_Data) + (num * Led_Data_Len); //指针偏移:跳过RESET信号的N个0  //num为0时，指向第一个灯的首地址
    for (uint8_t i = 0; i < 8; ++i)                                 //进行装载
	p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
    for (uint8_t i = 8; i < 16; ++i)
	p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
    for (uint8_t i = 16; i < 24; ++i)
	p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);

}




//指定某灯写入缓冲数组函数2
void WS2812_Display_2( uint8_t red, uint8_t green, uint8_t blue,uint16_t num)
{

            uint8_t i;
            uint32_t Color=(green << 16 | red << 8 | blue);//将2个8位数据合并转化为32位数据类型

            //指针偏移:需要跳过复位信号的N个0
            uint16_t* p = (RGB_buffur + Reste_Data) + (num * Led_Data_Len);

            for (i = 0; i < 24; ++i)    //对数组进行编辑
			p[i]= (((Color << i) & 0X800000) ? Hight_Data : Low_Data);

}


//几个灯一次性写入缓冲数组函数
void WS2812_Number_4(uint32_t Color1,uint32_t Color2,uint32_t Color3,uint32_t Color4)
{

    uint16_t  RGB_Buff_4[Reste_Data + 4 * WS2812_Data_Len] = { 0 };
    uint16_t* p;
    uint32_t Color;

    for( uint8_t k=0;k<4;k++)
  {
      switch (k)    //进行指针偏移，准备写入数组
      {
        case 0: p= (RGB_Buff_4 + Reste_Data) + (0 * Led_Data_Len),Color=Color1;break;
        case 1: p= (RGB_Buff_4 + Reste_Data) + (1 * Led_Data_Len),Color=Color2;break;
        case 2: p= (RGB_Buff_4 + Reste_Data) + (2 * Led_Data_Len),Color=Color3;break;
        case 3: p= (RGB_Buff_4 + Reste_Data) + (3 * Led_Data_Len),Color=Color4;break;
        default : ;break;
      }

     for (uint8_t i = 0; i < 8; ++i)   //color数据写入数组
    {
        for (uint8_t i = 0; i < 8; ++i)
        p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
        for (uint8_t i = 8; i < 16; ++i)
        p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
        for (uint8_t i = 16; i < 24; ++i)
        p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
    }

 }

    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_Buff_4,(176));//启动DMA传输 176个半字
 //从内存到外设（PWM口）传输数据  外设口 数据首地址（(uint32_t *)：HAL函数要求类型，所以对地址强制类型） 数据长度（单位：半字16bit）

}


//蓝灯全亮
void WS2812_Init(void)//num:1 2 3 4...
{
		uint32_t Color0=0x000000; //无
		uint32_t Color1=0x00001F; //绿
	  uint32_t Color2=0x00001F;
		uint32_t Color3=0x00001F;
		uint32_t Color4=0x00001F; //黄
		uint32_t Color5=0x00001F;
		uint32_t Color6=0x00001F;
		uint32_t Color7=0x00001F; //红
		uint32_t Color8=0x00001F;
		uint32_t Color9=0x00001F;
	
//	RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len] = 0;
// __attribute__((section (".RAM_D3"))) static uint16_t  RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len] = { 0 };
//    uint16_t  RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len] = { 0 };//Reste_Data + 9 * WS2812_Data_Len
//		0x20000BF0   0x24000BF0
		uint8_t num=9;
    uint16_t* p;
    uint32_t Color;

    for( uint8_t k=0;k<9;k++)
  {
      switch (k)    //进行指针偏移，准备写入数组
      {
        case 0: p= (RGB_Buff_9 + Reste_Data) + (0 * Led_Data_Len),Color=Color1;break;
        case 1: p= (RGB_Buff_9 + Reste_Data) + (1 * Led_Data_Len),Color=Color2;break;
        case 2: p= (RGB_Buff_9 + Reste_Data) + (2 * Led_Data_Len),Color=Color3;break;
        case 3: p= (RGB_Buff_9 + Reste_Data) + (3 * Led_Data_Len),Color=Color4;break;
	      case 4: p= (RGB_Buff_9 + Reste_Data) + (4 * Led_Data_Len),Color=Color5;break;
        case 5: p= (RGB_Buff_9 + Reste_Data) + (5 * Led_Data_Len),Color=Color6;break;
        case 6: p= (RGB_Buff_9 + Reste_Data) + (6 * Led_Data_Len),Color=Color7;break;
        case 7: p= (RGB_Buff_9 + Reste_Data) + (7 * Led_Data_Len),Color=Color8;break;
				case 8: p= (RGB_Buff_9 + Reste_Data) + (8 * Led_Data_Len),Color=Color9;break;
        default : ;break;
      }
			
			if( k>=num )
			{
				Color =Color0;
			}

     for (uint8_t i = 0; i < 8; ++i)   //color数据写入数组 一个color占24个数组数
			{
        for (uint8_t i = 0; i < 8; ++i)
        p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//相对数组8-16位
        for (uint8_t i = 8; i < 16; ++i)
        p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//相对数组1-8位
        for (uint8_t i = 16; i < 24; ++i)
        p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);  //相对数组16-24位
			}

 }

    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_Buff_9,(276));//启动DMA传输 50+24*9（+10）个半字266
 //从内存到外设（PWM口）传输数据  外设口 数据首地址（(uint32_t *)：HAL函数要求类型，所以对地址强制类型） 数据长度（单位：半字16bit）（缓存数组的一个数是一半字）

}




//跑马灯函数 底层驱动定制跑马灯应用
void WS2812_Marquee( uint8_t num )//num:1 2 3 4...
{
		uint32_t Color0=0x000000; //无
		uint32_t Color1=0x001F00; //绿
	  uint32_t Color2=0x001F00;
		uint32_t Color3=0x001F00;
		uint32_t Color4=0x201800; //黄
		uint32_t Color5=0x201800;
		uint32_t Color6=0x201800;
		uint32_t Color7=0x280000; //红
		uint32_t Color8=0x280000;
		uint32_t Color9=0x280000;
//		uint32_t Color10=0x0000FF;
//	RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len] = 0;
// __attribute__((section (".RAM_D3"))) static uint16_t  RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len] = { 0 };
//    uint16_t  RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len] = { 0 };//Reste_Data + 9 * WS2812_Data_Len
//		0x20000BF0   0x24000BF0

    uint16_t* p;
    uint32_t Color;

	if( num < 10 )
    for( uint8_t k=0;k<9;k++)
  {
      switch (k)    //进行指针偏移，准备写入数组
      {
        case 0: p= (RGB_Buff_9 + Reste_Data) + (0 * Led_Data_Len),Color=Color1;break;
        case 1: p= (RGB_Buff_9 + Reste_Data) + (1 * Led_Data_Len),Color=Color2;break;
        case 2: p= (RGB_Buff_9 + Reste_Data) + (2 * Led_Data_Len),Color=Color3;break;
        case 3: p= (RGB_Buff_9 + Reste_Data) + (3 * Led_Data_Len),Color=Color4;break;
	      case 4: p= (RGB_Buff_9 + Reste_Data) + (4 * Led_Data_Len),Color=Color5;break;
        case 5: p= (RGB_Buff_9 + Reste_Data) + (5 * Led_Data_Len),Color=Color6;break;
        case 6: p= (RGB_Buff_9 + Reste_Data) + (6 * Led_Data_Len),Color=Color7;break;
        case 7: p= (RGB_Buff_9 + Reste_Data) + (7 * Led_Data_Len),Color=Color8;break;
				case 8: p= (RGB_Buff_9 + Reste_Data) + (8 * Led_Data_Len),Color=Color9;break;
        default : ;break;
      }
			
			if( k>=num )
			{
				Color =Color0;
			}

     for (uint8_t i = 0; i < 8; ++i)   //color数据写入数组 一个color占24个数组数
			{
        for (uint8_t i = 0; i < 8; ++i)
        p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//相对数组8-16位
        for (uint8_t i = 8; i < 16; ++i)
        p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//相对数组1-8位
        for (uint8_t i = 16; i < 24; ++i)
        p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);  //相对数组16-24位
			}

 }
	else
		WS2812_Init();
		
    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_Buff_9,(276));//启动DMA传输 50+24*9（+10）个半字266
 //从内存到外设（PWM口）传输数据  外设口 数据首地址（(uint32_t *)：HAL函数要求类型，所以对地址强制类型） 数据长度（单位：半字16bit）（缓存数组的一个数是一半字）
		SCB_InvalidateDCache();
}


//DMA传输完成会执行该回调函数（已被弱定义函数）//中断回调函数不要写延时！
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(&htim3,TIM_CHANNEL_2);
	//HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
//	  printf("finish DMA \r\n");
}


/*函数应用示例
main.c中函数调用
//点亮4个灯\n
      WS2812_Display_1(0x180000, 0);//red
      WS2812_Display_1(0x001800, 1);//green
      WS2812_Display_1(0x000018, 2);//blue
      WS2812_Display_1(0x181818, 3);//white
      HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_buffur,(176));//启动DMA传输

//以下代码和上述效果一致，只是颜色数据表示形式不一样\n
      WS2812_Display_2( 22 , 0 , 0, 0);
      WS2812_Display_2(  0 , 22, 0, 1);
      WS2812_Display_2(  0 , 0, 22, 2);
      WS2812_Display_2( 22, 22 , 22, 3);
      HAL_TIM_PWM_Start_DMA(&htim1,TIM_CHANNEL_1,(uint32_t *)RGB_buffur,(176));//启动DMA传输

while函数中调用：实现流水灯
	    WS2812_Number_4(0x180000,0x001800,0x000018,0);
	    HAL_Delay(500);
	    WS2812_Number_4(0,0x180000,0x001800,0x000018);
	    HAL_Delay(500);
	    WS2812_Number_4(0x000018,0,0x180000,0x001800);
	    HAL_Delay(500);
	    WS2812_Number_4(0x001800,0x000018,0,0x180000);
	    HAL_Delay(500);
			
跑马灯应用
			WS2812_Marquee(9);  			//开启跑马灯，显示9串
*/

#endif