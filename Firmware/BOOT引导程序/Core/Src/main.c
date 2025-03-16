/***
	*************************************************************************************************
	*	@file  	main.c
	*	@version V1.0
	*  @date    2020-8-4
	*	@author  反客科技	
	*	@brief   QSPI驱动W25Q64，跳转到W25Q64运行
   *************************************************************************************************
   *  @description
	*
	*	实验平台：反客STM32H7B0VBT6核心板 （型号：FK7B0M1-VBT6）
	*	淘宝地址：https://shop212360197.taobao.com
	*	QQ交流群：536665479
	*
>>>>> 功能说明：
	*
	*	1.初始化时钟和OQSPI，并且将W25Q64映射为内部存储器
	*	2.跳转到W25Q64运行用户程序
	*
>>>>> 串口打印说明：
	*
	*	USART1使用的是PA9/PA10，串口波特率115200
	*	
	************************************************************************************************
***/	

#include "main.h"
#include "led.h"
#include "key.h"
#include "usart.h"
#include "ospi_w25q64.h"

/********************************************** 变量定义 *******************************************/

typedef  void (*pFunction)(void);

pFunction JumpToApplication;

/********************************************** 函数声明 *******************************************/

void SystemClock_Config(void);		// 时钟初始化


/***************************************************************************************************
*	函 数 名: main
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 跳转到W25Q64
*	说    明: 无
****************************************************************************************************/

int main(void)
{
	SCB_EnableICache();		// 使能ICache（指令缓存），缓存指令，加快访问指令速度（CPU-寄存器-cache-DDR
	SCB_EnableDCache();		// 使能DCache（数据缓存），缓存数据
	HAL_Init();					// 初始化HAL库
	SystemClock_Config();	// 配置系统时钟，主频280MHz
	LED_Init();					// 初始化LED引脚
	USART1_Init();				// USART1初始化	

	printf("\r\n***************************************\r\n");
		
	OSPI_W25Qxx_Init();		// 初始化OSPI和W25Q64
	OSPI_W25Qxx_MemoryMappedMode(); 	 // 配置QSPI为内存映射模式	

	SCB_DisableICache();		// 关闭ICache
	SCB_DisableDCache();		// 关闭Dcache

	
	SysTick->CTRL = 0;		// 关闭SysTick
	SysTick->LOAD = 0;		// 清零重载值
	SysTick->VAL = 0;			// 清零计数值

	JumpToApplication = (pFunction) (*(__IO uint32_t*) (W25Qxx_Mem_Addr + 4));	// 设置起始地址
	__set_MSP(*(__IO uint32_t*) W25Qxx_Mem_Addr);	// 设置主堆栈指针
	printf("跳转到W25Q64运行用户程序>>>\r\n\r\n");

	JumpToApplication();			// 执行跳转	
	
	while (1)
	{

	}
}

/****************************************************************************************************/
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 280000000 (CPU Clock)
  *            HCLK(Hz)                       = 280000000 (AXI and AHBs Clock)
  *            AHB Prescaler                  = 1 (AHB  Clock  280MHz)
  *            D1 APB3 Prescaler              = 2 (APB3 Clock  140MHz)
  *            D2 APB1 Prescaler              = 2 (APB1 Clock  140MHz)
  *            D2 APB2 Prescaler              = 2 (APB2 Clock  140MHz)
  *            D3 APB4 Prescaler              = 2 (APB4 Clock  140MHz)
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 5
  *            PLL_N                          = 112
  *            PLL_P                          = 2
  *            PLL_Q                          = 2
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  
  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Macro to configure the PLL clock source
  */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 112;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  } 

	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_OSPI;
 
	/* 为了设置方便，将 系统主时钟HCLK 作为OSPI的内核时钟，速度为280M，再经过2分频得到140M驱动时钟  */  
	/* HCLK 也是OSPI的默认的内核时钟，在使用XIP时（在OSPI外设运行代码），也只能使用默认的时钟 */
	/* 因此，虽然140M已经超出了 W25Q64JV 所允许的最高时钟，但还是将OSPI的驱动时钟设置为140M */
	/* 实际测试中，将驱动时钟拉到将近200M，w25q64还是可以正常读写，所以只超出7M的频率不用担心稳定性*/  
	PeriphClkInitStruct.OspiClockSelection = RCC_OSPICLKSOURCE_D1HCLK;
  
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
	Error_Handler();
	}  
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
