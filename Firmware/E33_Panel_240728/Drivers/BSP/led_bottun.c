//��1ʹ�ܸ�������/�ű���
#if 1

/*
led����ť��������
led:PC1 PE1
bottun:PC13

���ť���飺PE0
*/

#include "led_bottun.h"

//HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)==1;


//Ϊmain�������ú���
void led_bottun()
{
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
}

uint8_t key_scan(uint8_t botton)//�ĸ��������£�����ʲôֵ��ģ��ATKESP8266������İ�����
{
	
//	#define KEY0_PRES    1                  /* KEY0���� */
//	#define KEY1_PRES    2                  /* KEY1���� */
//	#define KEY2_PRES    3                  /* KEY2���� */
//	#define WKUP_PRES    4                  /* KEY_UP����(��WK_UP) */
	
	return botton;
}
#endif