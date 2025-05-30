//置1使能该驱动库/脚本库
#if 1

//读取思路：检测下降沿（检测个数)  当A口处于下降沿，触发中断，执行回调函数
//脉冲计数器（PCNT）

#include "encoder.h"
#include "mycan.h"
#include "myusart.h"

uint8_t gpioreadfinish=0;	//GPIO读取中断标志位

//硬件连接：A口接 B口接地 C口接


//放中断回调函数执行
void encoder_handle(void)
{
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET)//编码器顺时针，C口处于高电平
	{
		//右加一
	}
	else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET)//编码器逆时针，C口处于低电平
	{
		//
	}
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)//外部触发中断暂时只处理编码器按钮按下信号发送报文
{
//	static uint8_t DRS_State=0;//存储并记住DRS状态信息 后面配合CAN接收DRS情况校准(可能存在ID优先级占用问题) 起始关闭
	uint8_t gpioreadfinish=1;
}

//void my_GPIO_Read_Callback(void)
//{
//	//发送CAN报文
//	uint8_t res;
//	
//	if(gpioreadfinish==1)
//	{
//		HAL_Delay(300);
//	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9)==0)	//按钮闭合
//	{
//		//DRS开启
//	TxData[0]=1;
//		
//	res = Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202); // 发送8个字节 返回值0成功，返回其他则失败  
//	if (res==0)
//		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202);		 //再重发一次
//	 else 
//		myprintf("CAN Convey Finish\r\n");           	// 提示发送成功 
//	}
//	
//	else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9)==1)	//按钮未闭合
//	{
//		//DRS关闭
//	TxData[0]=2;
//		
//	res = Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202); // 发送8个字节 返回值0成功，返回其他则失败  
//	if (res==0)
//		Fdcan_Send_Msg(TxData, FDCAN_DLC_BYTES_1,0x202);		 //再重发一次//可能存在ID优先级占用问题
//  else 
//		myprintf("CAN Convey Finish\r\n");           // 提示发送成功 
//}
//	gpioreadfinish=0;
//	}
//}

//模板
/*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_9)
	{
	  if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9)==GPIO_PIN_RESET)//浜疆0锛孡ED锟??
	  {

			  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	  }
	}
	else if(GPIO_Pin==GPIO_PIN_13)
			  HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_1);
}
*/



//你的keypad扫描函数
uint8_t	KEY_Scan1(void)
{
	uint8_t i;
	i=(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_7)==GPIO_PIN_RESET)+(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_8)==GPIO_PIN_RESET)+(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_9)==GPIO_PIN_RESET);
	if(i!=0)	//检测按键是否被按下
	{	
		HAL_Delay(10);	//延时消抖
		if( HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_7) == 0)	//再次检测是否为低电平
		{
			while(  HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_7) == 0);	//等待按键放开
			return 1;	//返回按键按下标志
		}
		if( HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_8) == 0)	//再次检测是否为低电平
		{
			while(  HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_8) == 0);	//等待按键放开
			return 2;	//返回按键按下标志
		}
		if( HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_9) == 0)	//再次检测是否为低电平
		{
			while(  HAL_GPIO_ReadPin (GPIOE,GPIO_PIN_9) == 0);	//等待按键放开
			return 3;	//返回按键按下标志
		}
		
	}
	return 0;	
}


//野火按键扫描函数
/**
 * @brief       按键扫描函数
 * @note        该函数有响应优先级(同时按下多个按键): WK_UP > KEY1 > KEY0!!
 * @param       mode:0 / 1, 具体含义如下:
 *   @arg       0,  不支持连续按(当按键按下不放时, 只有第一次调用会返回键值,
 *                  必须松开以后, 再次按下才会返回其他键值)
 *   @arg       1,  支持连续按(当按键按下不放时, 每次调用该函数都会返回键值)
 * @retval      键值, 定义如下:
 *              KEY0_PRES, 1, KEY0按下
 *              KEY1_PRES, 2, KEY1按下
 *              WKUP_PRES, 3, WKUP按下
 */
uint8_t key_scan2(uint8_t mode)
{
    static uint8_t key_up = 1;  /* 按键按松开标志 */
    uint8_t keyval = 0;

    if (mode) key_up = 1;       /* 支持连按 */

    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0))  /* 按键松开标志为1, 且有任意一个按键按下了 */
    {
        HAL_Delay(10);           /* 去抖动 */
        key_up = 0;

        if (KEY0 == 0)  keyval = 1;

        if (KEY1 == 0)  keyval = 2;

        if (KEY2 == 0)  keyval = 3;
    }
    else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 0) /* 没有任何按键按下, 标记按键松开 */
    {
        key_up = 1;
    }

    return keyval;              /* 返回键值 */
}



#endif
