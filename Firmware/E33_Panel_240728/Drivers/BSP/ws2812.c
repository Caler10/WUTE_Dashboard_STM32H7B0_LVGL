//��1ʹ�ܸ�������/�ű���
#if 1

/*
������������16λ�Զ����ؼ�������ʱ������
ԭTIM3CHANNEL2���������ɹ����̼�IDE��
���ţ�PB5 TIM3CH2
*/

/*
�������̣�
RESET                                        �ֲ�֪������50΢�루��Ϊ50PWM������λ�ɣ�
��һ����RGB���� 00000000 00000000 00000000    ����0���ߵ͵�ƽʱ��ȣ�8��17
�ڶ�����RGB���� 00000000 00000000 00000000    ����1���ߵ͵�ƽʱ��ȣ�16��9
......
*/

#include "myusart.h"
#include "ws2812.h"
#include "main.h"
#include "tim.h"

//���ݻ�������
uint16_t RGB_buffur[Reste_Data + WS2812_Data_Len] = { 0 }; 
//��PWM:ÿ���������ÿ��PWM���ڸߵ�ƽ����ֵ=�Զ�����ֵ*ռ�ձȣ�so����0С���Զ�����ֵ�� �洢��ʽ��16λ��������

//uint32_t *RGB_Buff_9 = 0x24001000;//��һ�ֳ���
//__align(8) uint8_t value[20] __attribute__((at(0x20000100)));//�ڶ��ֳ���
__attribute__((section (".RAM_D3"))) uint16_t  RGB_Buff_9[Reste_Data + 4 * WS2812_Data_Len];//�����ֳ��� ȫ�ֱ��������ڸ�.c�ļ���ʹ�ã�
//�������ֻ���������ø�0Ҳ��

//ָ��ĳ��д�뻺�����麯��1
//��ɫ���ݴ����ʽ��RGB888  num��0 1 2 3���Ƶ�λ�ã�
void WS2812_Display_1(uint32_t Color, uint16_t num)
{
    uint16_t* p = (RGB_buffur + Reste_Data) + (num * Led_Data_Len); //ָ��ƫ��:����RESET�źŵ�N��0  //numΪ0ʱ��ָ���һ���Ƶ��׵�ַ
    for (uint8_t i = 0; i < 8; ++i)                                 //����װ��
	p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
    for (uint8_t i = 8; i < 16; ++i)
	p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
    for (uint8_t i = 16; i < 24; ++i)
	p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);

}




//ָ��ĳ��д�뻺�����麯��2
void WS2812_Display_2( uint8_t red, uint8_t green, uint8_t blue,uint16_t num)
{

            uint8_t i;
            uint32_t Color=(green << 16 | red << 8 | blue);//��2��8λ���ݺϲ�ת��Ϊ32λ��������

            //ָ��ƫ��:��Ҫ������λ�źŵ�N��0
            uint16_t* p = (RGB_buffur + Reste_Data) + (num * Led_Data_Len);

            for (i = 0; i < 24; ++i)    //��������б༭
			p[i]= (((Color << i) & 0X800000) ? Hight_Data : Low_Data);

}


//������һ����д�뻺�����麯��
void WS2812_Number_4(uint32_t Color1,uint32_t Color2,uint32_t Color3,uint32_t Color4)
{

    uint16_t  RGB_Buff_4[Reste_Data + 4 * WS2812_Data_Len] = { 0 };
    uint16_t* p;
    uint32_t Color;

    for( uint8_t k=0;k<4;k++)
  {
      switch (k)    //����ָ��ƫ�ƣ�׼��д������
      {
        case 0: p= (RGB_Buff_4 + Reste_Data) + (0 * Led_Data_Len),Color=Color1;break;
        case 1: p= (RGB_Buff_4 + Reste_Data) + (1 * Led_Data_Len),Color=Color2;break;
        case 2: p= (RGB_Buff_4 + Reste_Data) + (2 * Led_Data_Len),Color=Color3;break;
        case 3: p= (RGB_Buff_4 + Reste_Data) + (3 * Led_Data_Len),Color=Color4;break;
        default : ;break;
      }

     for (uint8_t i = 0; i < 8; ++i)   //color����д������
    {
        for (uint8_t i = 0; i < 8; ++i)
        p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
        for (uint8_t i = 8; i < 16; ++i)
        p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
        for (uint8_t i = 16; i < 24; ++i)
        p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);
    }

 }

    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_Buff_4,(176));//����DMA���� 176������
 //���ڴ浽���裨PWM�ڣ���������  ����� �����׵�ַ��(uint32_t *)��HAL����Ҫ�����ͣ����ԶԵ�ַǿ�����ͣ� ���ݳ��ȣ���λ������16bit��

}


//����ȫ��
void WS2812_Init(void)//num:1 2 3 4...
{
		uint32_t Color0=0x000000; //��
		uint32_t Color1=0x00001F; //��
	  uint32_t Color2=0x00001F;
		uint32_t Color3=0x00001F;
		uint32_t Color4=0x00001F; //��
		uint32_t Color5=0x00001F;
		uint32_t Color6=0x00001F;
		uint32_t Color7=0x00001F; //��
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
      switch (k)    //����ָ��ƫ�ƣ�׼��д������
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

     for (uint8_t i = 0; i < 8; ++i)   //color����д������ һ��colorռ24��������
			{
        for (uint8_t i = 0; i < 8; ++i)
        p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//�������8-16λ
        for (uint8_t i = 8; i < 16; ++i)
        p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//�������1-8λ
        for (uint8_t i = 16; i < 24; ++i)
        p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);  //�������16-24λ
			}

 }

    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_Buff_9,(276));//����DMA���� 50+24*9��+10��������266
 //���ڴ浽���裨PWM�ڣ���������  ����� �����׵�ַ��(uint32_t *)��HAL����Ҫ�����ͣ����ԶԵ�ַǿ�����ͣ� ���ݳ��ȣ���λ������16bit�������������һ������һ���֣�

}




//����ƺ��� �ײ��������������Ӧ��
void WS2812_Marquee( uint8_t num )//num:1 2 3 4...
{
		uint32_t Color0=0x000000; //��
		uint32_t Color1=0x001F00; //��
	  uint32_t Color2=0x001F00;
		uint32_t Color3=0x001F00;
		uint32_t Color4=0x201800; //��
		uint32_t Color5=0x201800;
		uint32_t Color6=0x201800;
		uint32_t Color7=0x280000; //��
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
      switch (k)    //����ָ��ƫ�ƣ�׼��д������
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

     for (uint8_t i = 0; i < 8; ++i)   //color����д������ һ��colorռ24��������
			{
        for (uint8_t i = 0; i < 8; ++i)
        p[i+8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//�������8-16λ
        for (uint8_t i = 8; i < 16; ++i)
        p[i-8]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);//�������1-8λ
        for (uint8_t i = 16; i < 24; ++i)
        p[i]= (((Color << i) & 0X800000) ? Hight_Data :Low_Data);  //�������16-24λ
			}

 }
	else
		WS2812_Init();
		
    HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_Buff_9,(276));//����DMA���� 50+24*9��+10��������266
 //���ڴ浽���裨PWM�ڣ���������  ����� �����׵�ַ��(uint32_t *)��HAL����Ҫ�����ͣ����ԶԵ�ַǿ�����ͣ� ���ݳ��ȣ���λ������16bit�������������һ������һ���֣�
		SCB_InvalidateDCache();
}


//DMA������ɻ�ִ�иûص��������ѱ������庯����//�жϻص�������Ҫд��ʱ��
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(&htim3,TIM_CHANNEL_2);
	//HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
//	  printf("finish DMA \r\n");
}


/*����Ӧ��ʾ��
main.c�к�������
//����4����\n
      WS2812_Display_1(0x180000, 0);//red
      WS2812_Display_1(0x001800, 1);//green
      WS2812_Display_1(0x000018, 2);//blue
      WS2812_Display_1(0x181818, 3);//white
      HAL_TIM_PWM_Start_DMA(&htim3,TIM_CHANNEL_2,(uint32_t *)RGB_buffur,(176));//����DMA����

//���´��������Ч��һ�£�ֻ����ɫ���ݱ�ʾ��ʽ��һ��\n
      WS2812_Display_2( 22 , 0 , 0, 0);
      WS2812_Display_2(  0 , 22, 0, 1);
      WS2812_Display_2(  0 , 0, 22, 2);
      WS2812_Display_2( 22, 22 , 22, 3);
      HAL_TIM_PWM_Start_DMA(&htim1,TIM_CHANNEL_1,(uint32_t *)RGB_buffur,(176));//����DMA����

while�����е��ã�ʵ����ˮ��
	    WS2812_Number_4(0x180000,0x001800,0x000018,0);
	    HAL_Delay(500);
	    WS2812_Number_4(0,0x180000,0x001800,0x000018);
	    HAL_Delay(500);
	    WS2812_Number_4(0x000018,0,0x180000,0x001800);
	    HAL_Delay(500);
	    WS2812_Number_4(0x001800,0x000018,0,0x180000);
	    HAL_Delay(500);
			
�����Ӧ��
			WS2812_Marquee(9);  			//��������ƣ���ʾ9��
*/

#endif