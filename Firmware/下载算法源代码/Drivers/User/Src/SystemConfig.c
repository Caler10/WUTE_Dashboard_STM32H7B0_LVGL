
#include "SystemConfig.h"

// ��ֲ�ڹٷ� STM32H7B3I/B0_EVAL �忨
/** @defgroup STM32H7B3I/B0_EVAL_OSPI_Exported_Functions Exported Functions
  * @{
  */

 /**
  * @brief  Initializes the OSPI interface.
  * @param  Instance   OSPI Instance
  * @param  Init       OSPI Init structure
  * @retval BSP status
  */
 HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{ 
  return HAL_OK;
}


// ϵͳʱ�ӳ�ʼ��

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
/****************************************************************************************************/
int SystemClock_Config(void)
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
    return 1;
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
    return 1;
  }
  
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_OSPI;
 
	/* Ϊ�����÷��㣬�� ϵͳ��ʱ��HCLK ��ΪOSPI���ں�ʱ�ӣ��ٶ�Ϊ280M���پ���2��Ƶ�õ�140M����ʱ��  */  
	/* HCLK Ҳ��OSPI��Ĭ�ϵ��ں�ʱ�ӣ���ʹ��XIPʱ����OSPI�������д��룩��Ҳֻ��ʹ��Ĭ�ϵ�ʱ�� */
	/* ��ˣ���Ȼ140M�Ѿ������� W25Q64JV ����������ʱ�ӣ������ǽ�OSPI������ʱ������Ϊ140M */
	/* ʵ�ʲ����У�������ʱ����������200M��w25q64���ǿ���������д������ֻ����7M��Ƶ�ʲ��õ����ȶ���*/  
	PeriphClkInitStruct.OspiClockSelection = RCC_OSPICLKSOURCE_D1HCLK;
  
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
		return 1;
	}  	
	return 0;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
