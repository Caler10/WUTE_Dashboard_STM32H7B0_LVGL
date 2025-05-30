
#ifndef __CAN_H__
#define __CAN_H__

#include "main.h"


	
extern FDCAN_TxHeaderTypeDef     TxHeader;            /* 发送消息 */
extern FDCAN_RxHeaderTypeDef     RxHeader;            /* 接收消息 */
extern uint8_t RxData[32];		
extern uint8_t TxData[8];

void FDCAN2_Filter_Config(void);
uint8_t Fdcan_Send_Msg(uint8_t *msg, uint32_t len,uint32_t canID);
uint8_t Fdcan_Receive_Msg(uint8_t *buf);


#endif