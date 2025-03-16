//��1ʹ�ܸ�������
#if 1

/*
������Ӳ������֧��RGB666����������RGB565
�������ӣ�
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
RGBTFT���⼰��ʾ
*/

#include "rgbtft.h"
#include "tim.h"

/*********************************��������**************************************/

static uint16_t LCD_PwmPeriod = 500;  		//��ʱ������ֵ

//���⿪��
void RGBTFT_Backlight_Open()
{
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 500); //���ñȽϼĴ���
  HAL_TIM_PWM_Start (&htim4, TIM_CHANNEL_4);//���⿪��������
}


//�ٷ��Ƶ��⺯��  pulse��Χ:[1,100]����compareValue��Χ��[5��500]
void  LCD_PwmSetPulse (uint8_t pulse)
{
	uint16_t compareValue ; 
	
	compareValue = pulse * LCD_PwmPeriod / 100; //����ռ�ձ����ñȽ�ֵ

	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, compareValue); //���ñȽϼĴ���
	
  HAL_TIM_PWM_Start (&htim4, TIM_CHANNEL_4);//���⿪��������
//	TIM4->CCR4 = compareValue; 			// �޸�TIM4��ͨ��4�Ƚ�ֵ
}


/********************************��ʾ����************************************/

//ȫ����д����
void RGBTFT_Clear(uint16_t color)
{
	uint32_t i;
	while(LTDC->CDSR!=0x00000001);
	for(i=0;i<(800*480);i++)
	{
		*(uint16_t*)(LCD_MemoryAdd+i*2)=color;
	}
}

//�Դ滭�㺯��
void RGBTFT_Drawpoint(uint8_t x,uint8_t y)
{
		*(uint32_t*)(0x24000000+2*(x+800*y))=0xFFFF;
}

//������ƺ���
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

//������˺����������Ļ��������Դ���������
void GUI_DrawPoint(uint16_t x,uint16_t y,uint32_t *color)
{
		while(LTDC->CDSR!=0x00000001);
		*(uint16_t*)(LCD_MemoryAdd+(y*800+x)*2)=*color;
}

//DMA2D���ƻ���������ʾ��
//x:ˮƽ���� y:��ֱ���� wide: ͼƬ��ˮƽ��� heig- ͼƬ�Ĵ�ֱ���*color - Ҫ���ƵĻ�������ַ
//ע�⣺Ҫ���Ƶ������ܳ�����Ļ����ʾ����
//			�� lv_port_disp.c �ļ��У������� disp_flush() ���ã�����ˢ����ʾ����		
void RGBTFT_CopyBuffer(uint16_t x, uint16_t y, uint16_t width, uint16_t height,uint32_t *color)
{

	DMA2D->CR	  &=	~(DMA2D_CR_START);				//	ֹͣDMA2D
	DMA2D->CR		=	DMA2D_M2M;							//	�洢�����洢��
	DMA2D->FGPFCCR	=	LTDC_PIXEL_FORMAT_RGB565;		//	������ɫ��ʽ
  DMA2D->FGOR    =  0;										// 
	DMA2D->OOR		=	800 - width;				//	������ƫ�� 	
	DMA2D->FGMAR   =  (uint32_t)color;		
	DMA2D->OMAR		=	0x24000000 + 2*(800 * y + x);	// ��ַ;
	DMA2D->NLR		=	(width<<16)|(height);			//	�趨���ȺͿ��		
	DMA2D->CR	  |=	DMA2D_CR_START;					//	����DMA2D
		
	while (DMA2D->CR & DMA2D_CR_START) ;			//	�ȴ��������

}

/*
����LVGL��ֲ
setup_scr_screen.c�����
	extern lv_indev_t * indev_keypad;//�����봫������
//	lv_obj_t * obj;
	lv_group_t *g= lv_group_create();
	lv_group_set_default(g);
//	lv_group_add_obj(g, obj);
	lv_indev_set_group(indev_keypad,g);

*/

#endif