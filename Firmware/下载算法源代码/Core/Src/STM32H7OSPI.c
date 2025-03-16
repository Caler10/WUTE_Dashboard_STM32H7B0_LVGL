/**
  ******************************************************************************
  * @file    STM32H7OSPI.c
  * @author  MCD Application Team
  * @brief   This file defines the operations of the external loader for
  *          MX25LM51245G OSPI memory of STM32H7B3I/B0-EVAL.
  *           
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

#include "STM32H7OSPI.h"
#include <string.h>


/* Private functions ---------------------------------------------------------*/

/** @defgroup STM32H7B3I/B0_EVAL_OSPI_Private_Functions Private Functions
  * @{
  */

void HAL_Delay(uint32_t Delay)
{
  int i=0;
  for (i=0; i<0x1000; i++);
}
 uint32_t HAL_GetTick(void)
{
  int i;
  for (i=0;i<1024;i++);
  uwTick++;
  return uwTick;
}
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



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
