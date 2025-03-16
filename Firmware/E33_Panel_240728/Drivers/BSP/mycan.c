//置1使能该驱动库/脚本库
#if 1

//FDCAN MX配置：
//FDCAN配置的经典CAN模式，改为了250k波特率


#include "fdcan.h"
#include "mycan.h"
#include "myusart.h"
#include "stm32h7xx_hal.h"

FDCAN_TxHeaderTypeDef     TxHeader;            /* 发送消息 */
FDCAN_RxHeaderTypeDef     RxHeader;            /* 接收消息 */
uint8_t RxData[32];
uint8_t TxData[8]={0};

//配置CAN过滤器
void FDCAN2_Filter_Config(void)
{
		FDCAN_FilterTypeDef fdcan_filterconfig;
	
    fdcan_filterconfig.IdType = FDCAN_EXTENDED_ID;                   /* 拓展ID */
    fdcan_filterconfig.FilterIndex = 0;                              /* 滤波器索引 */
    fdcan_filterconfig.FilterType = FDCAN_FILTER_MASK;               /* 滤波器类型 */
    fdcan_filterconfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;       /* 过滤器0关联到FIFO0 */
    fdcan_filterconfig.FilterID1 = 0x0000;                           /* 32位ID */
    fdcan_filterconfig.FilterID2 = 0x0000;                           /* 如果FDCAN配置为传统模式的话，这里是32位掩码 */ //接收所有帧（原理ID1与ID2求&运算,结果要与掩码同才通过）
    
     /* 过滤器配置 */
    if (HAL_FDCAN_ConfigFilter(&hfdcan2, &fdcan_filterconfig) != HAL_OK) 
    {
     Error_Handler();                                                  /* 滤波器初始化 */
    }
		
    HAL_FDCAN_Start(&hfdcan2);                               // 开启FDCAN 
    HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);  //激活中断通知

}

/**
 * @brief       can发送一组数据(固定格式:ID为0X12,标准帧,数据帧)
 * @param       len:数据长度(最大为8) 单位：byte
 * @param       msg:数据指针,最大为8个字节.
 * @retval      返回值:0,成功;
 * @retval      其他,失败;
 */
uint8_t Fdcan_Send_Msg(uint8_t *msg, uint32_t len,uint32_t canID)
{
    TxHeader.Identifier = canID;                        /* 32位ID */
    TxHeader.IdType = FDCAN_EXTENDED_ID;                     /* 拓展ID */
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;                 /* 发送使用数据帧（数据帧：传出数据；遥控帧：请发数据） */
    TxHeader.DataLength = len;                               /* 数据长度 */
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;                  /* 关闭速率切换 */
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;                   /* 传统的CAN模式 */
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;        /* 无发送事件 */
    TxHeader.MessageMarker = 0;

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader, msg) != HAL_OK) /* 发送消息 */
    {
        return 1;
    }

    return 0;
}


/**getCAN报文并返回CAN报文数据长度
 * @brief       can口接收数据查询
 * @param       buf:数据缓存区
 * @retval      返回值:0,无数据被收到;
 * @retval      其他,接收的数据长度;
 */
uint8_t Fdcan_Receive_Msg(uint8_t *buf)
{
    if (HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, buf) != HAL_OK)   /* 接收数据 */
    {
        return 0;
    }

    return RxHeader.DataLength>>16;
}



//void HAL_FDCAN_xxxCallback()
	
void HAL_FDCAN_ErrorCallback(FDCAN_HandleTypeDef *hfdcan)
{
	myprintf("FDCAN error");
}

//HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, RxData);

//void HAL_FDCAN_RxBufferNewMessageCallback(FDCAN_HandleTypeDef *hfdcan)
//{
//	
//}



//函数应用示例

/*放在主函数循环里轮询读取CAN		
	rxlen = fdcan_receive_msg(canbuf);
	if (rxlen)                                                  // 接收到有数据 
  {
//     for (i = 0; i < rxlen; i++)
//       {
//         if (i < 4)
        myprintf("%d \r\n",canbuf[0]);              // 显示数据 
				WS2812_Marquee(canbuf[0]);//canbuf[0]
//       }
   }*/



#endif