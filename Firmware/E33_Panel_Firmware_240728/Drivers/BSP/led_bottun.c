//置1使能该驱动库/脚本库
#if 1

/*
led及按钮的驱动库
led:PC1 PE1
bottun:PC13

激活按钮灯珠：PE0
*/

#include "led_bottun.h"

//HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)==1;


//为main函数调用函数
void led_bottun()
{
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_1);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
}

uint8_t key_scan(uint8_t botton)//哪个按键按下，返回什么值（模拟ATKESP8266驱动里的按键）
{
	
//	#define KEY0_PRES    1                  /* KEY0按下 */
//	#define KEY1_PRES    2                  /* KEY1按下 */
//	#define KEY2_PRES    3                  /* KEY2按下 */
//	#define WKUP_PRES    4                  /* KEY_UP按下(即WK_UP) */
	
	return botton;
}
#endif