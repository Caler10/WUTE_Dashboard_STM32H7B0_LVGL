//��1ʹ�ܸ�������/�ű���
#if 1

//FDCAN MX���ã�
//FDCAN���õľ���CANģʽ����Ϊ��250k������


#include "fdcan.h"
#include "mycan.h"
#include "myusart.h"
#include "stm32h7xx_hal.h"

FDCAN_TxHeaderTypeDef     TxHeader;            /* ������Ϣ */
FDCAN_RxHeaderTypeDef     RxHeader;            /* ������Ϣ */
uint8_t RxData[32];
uint8_t TxData[8]={0};

//����CAN������
void FDCAN2_Filter_Config(void)
{
		FDCAN_FilterTypeDef fdcan_filterconfig;
	
    fdcan_filterconfig.IdType = FDCAN_EXTENDED_ID;                   /* ��չID */
    fdcan_filterconfig.FilterIndex = 0;                              /* �˲������� */
    fdcan_filterconfig.FilterType = FDCAN_FILTER_MASK;               /* �˲������� */
    fdcan_filterconfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;       /* ������0������FIFO0 */
    fdcan_filterconfig.FilterID1 = 0x0000;                           /* 32λID */
    fdcan_filterconfig.FilterID2 = 0x0000;                           /* ���FDCAN����Ϊ��ͳģʽ�Ļ���������32λ���� */ //��������֡��ԭ��ID1��ID2��&����,���Ҫ������ͬ��ͨ����
    
     /* ���������� */
    if (HAL_FDCAN_ConfigFilter(&hfdcan2, &fdcan_filterconfig) != HAL_OK) 
    {
     Error_Handler();                                                  /* �˲�����ʼ�� */
    }
		
    HAL_FDCAN_Start(&hfdcan2);                               // ����FDCAN 
    HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);  //�����ж�֪ͨ

}

/**
 * @brief       can����һ������(�̶���ʽ:IDΪ0X12,��׼֡,����֡)
 * @param       len:���ݳ���(���Ϊ8) ��λ��byte
 * @param       msg:����ָ��,���Ϊ8���ֽ�.
 * @retval      ����ֵ:0,�ɹ�;
 * @retval      ����,ʧ��;
 */
uint8_t Fdcan_Send_Msg(uint8_t *msg, uint32_t len,uint32_t canID)
{
    TxHeader.Identifier = canID;                        /* 32λID */
    TxHeader.IdType = FDCAN_EXTENDED_ID;                     /* ��չID */
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;                 /* ����ʹ������֡������֡���������ݣ�ң��֡���뷢���ݣ� */
    TxHeader.DataLength = len;                               /* ���ݳ��� */
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;                  /* �ر������л� */
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;                   /* ��ͳ��CANģʽ */
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;        /* �޷����¼� */
    TxHeader.MessageMarker = 0;

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader, msg) != HAL_OK) /* ������Ϣ */
    {
        return 1;
    }

    return 0;
}


/**getCAN���Ĳ�����CAN�������ݳ���
 * @brief       can�ڽ������ݲ�ѯ
 * @param       buf:���ݻ�����
 * @retval      ����ֵ:0,�����ݱ��յ�;
 * @retval      ����,���յ����ݳ���;
 */
uint8_t Fdcan_Receive_Msg(uint8_t *buf)
{
    if (HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, buf) != HAL_OK)   /* �������� */
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



//����Ӧ��ʾ��

/*����������ѭ������ѯ��ȡCAN		
	rxlen = fdcan_receive_msg(canbuf);
	if (rxlen)                                                  // ���յ������� 
  {
//     for (i = 0; i < rxlen; i++)
//       {
//         if (i < 4)
        myprintf("%d \r\n",canbuf[0]);              // ��ʾ���� 
				WS2812_Marquee(canbuf[0]);//canbuf[0]
//       }
   }*/



#endif