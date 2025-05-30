//置1使能该驱动库
#if 1

/*
方案：硬件连接支持RGB666，但驱动是RGB565
引脚连接：
    PB0     ------> LTDC_R3
    PA5     ------> LTDC_R4
    PC0     ------> LTDC_R5
		PB1     ------> LTDC_R6
    PE15     ------> LTDC_R7
    PA6     ------> LTDC_G2
    PE11     ------> LTDC_G3
		PB10     ------> LTDC_G4
    PB11     ------> LTDC_G5
    PC7     ------> LTDC_G6
    PD3     ------> LTDC_G7
    PD10     ------> LTDC_B3
    PE12     ------> LTDC_B4
		PA3     ------> LTDC_B5
    PB8     ------> LTDC_B6
    PB9     ------> LTDC_B7
    PE13     ------> LTDC_DE
    PE14     ------> LTDC_CLK
    PA7     ------> LTDC_VSYNC
    PC6     ------> LTDC_HSYNC
RGBTFT背光及显示
*/

#include "rgbtft.h"
#include "tim.h"

/*********************************背光驱动**************************************/

static uint16_t LCD_PwmPeriod = 500;  		//定时器重载值

//背光开启
void RGBTFT_Backlight_Open()
{
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 500); //配置比较寄存器
  HAL_TIM_PWM_Start (&htim4, TIM_CHANNEL_4);//背光开启，显形
}


//百分制调光函数  pulse范围:[1,100]，得compareValue范围：[5，500]
void  LCD_PwmSetPulse (uint8_t pulse)
{
	uint16_t compareValue ; 
	
	compareValue = pulse * LCD_PwmPeriod / 100; //根据占空比设置比较值

	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, compareValue); //配置比较寄存器
	
  HAL_TIM_PWM_Start (&htim4, TIM_CHANNEL_4);//背光开启，显形
//	TIM4->CCR4 = compareValue; 			// 修改TIM4的通道4比较值
}


/********************************显示驱动************************************/

//全屏擦写函数
void RGBTFT_Clear(uint16_t color)
{
	uint32_t i;
	while(LTDC->CDSR!=0x00000001);
	for(i=0;i<(800*480);i++)
	{
		*(uint16_t*)(LCD_MemoryAdd+i*2)=color;
	}
}

//显存画点函数
void RGBTFT_Drawpoint(uint8_t x,uint8_t y)
{
		*(uint32_t*)(0x24000000+2*(x+800*y))=0xFFFF;
}

//方块绘制函数
void RGBTFT_Drawblock(uint16_t wide,uint16_t color)
{
	uint32_t i,j;
	while(LTDC->CDSR!=0x00000001);
	for(i=0;i<wide;i++)
	{
		for(j=0;j<wide;j++)
		{
		*(uint16_t*)(LCD_MemoryAdd+(i*800+j)*2)=color;
		}
	}
}

//画点搬运函数（最慢的缓冲区到显存区方法）
void GUI_DrawPoint(uint16_t x,uint16_t y,uint32_t *color)
{
		while(LTDC->CDSR!=0x00000001);
		*(uint16_t*)(LCD_MemoryAdd+(y*800+x)*2)=*color;
}

//DMA2D复制缓冲区到显示区
//x:水平坐标 y:垂直坐标 wide: 图片的水平宽度 heig- 图片的垂直宽度*color - 要复制的缓冲区地址
//注意：要绘制的区域不能超过屏幕的显示区域
//			在 lv_port_disp.c 文件中，被函数 disp_flush() 调用，用以刷新显示区域		
void RGBTFT_CopyBuffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height,uint32_t *color)
{

	DMA2D->CR	  &=	~(DMA2D_CR_START);				//	停止DMA2D
	DMA2D->CR		=	DMA2D_M2M;							//	存储器到存储器
	DMA2D->FGPFCCR	=	LTDC_PIXEL_FORMAT_RGB565;		//	设置颜色格式
  DMA2D->FGOR    =  0;										// 
	DMA2D->OOR		=	800 - width;				//	设置行偏移 	
	DMA2D->FGMAR   =  (uint32_t)color;		
	DMA2D->OMAR		=	0x24000000 + 2*(800 * y + x);	// 地址;
	DMA2D->NLR		=	(width<<16)|(height);			//	设定长度和宽度		
	DMA2D->CR	  |=	DMA2D_CR_START;					//	启动DMA2D
		
	while (DMA2D->CR & DMA2D_CR_START) ;			//	等待传输完成

}

/*
关于LVGL移植
setup_scr_screen.c中添加
	extern lv_indev_t * indev_keypad;//从输入传进来的
//	lv_obj_t * obj;
	lv_group_t *g= lv_group_create();
	lv_group_set_default(g);
//	lv_group_add_obj(g, obj);
	lv_indev_set_group(indev_keypad,g);

*/

#endif