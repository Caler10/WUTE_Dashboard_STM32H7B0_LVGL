/**
 ****************************************************************************************************
 * @file        atk_mw8266d_uart.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-06-21
 * @brief       ATK-MW8266D模块UART接口驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 阿波罗 H743开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#ifndef __ATK_MW8266D_UART_H
#define __ATK_MW8266D_UART_H

#include "main.h"

/* 引脚定义 */
#if 1
#define ATK_MW8266D_UART_TX_GPIO_PORT           GPIOA
#define ATK_MW8266D_UART_TX_GPIO_PIN            GPIO_PIN_9
#define ATK_MW8266D_UART_TX_GPIO_AF             GPIO_AF7_USART1
#define ATK_MW8266D_UART_TX_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)     /* PB口时钟使能 */

#define ATK_MW8266D_UART_RX_GPIO_PORT           GPIOA
#define ATK_MW8266D_UART_RX_GPIO_PIN            GPIO_PIN_10
#define ATK_MW8266D_UART_RX_GPIO_AF             GPIO_AF7_USART1
#define ATK_MW8266D_UART_RX_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)     /* PB口时钟使能 */

#define ATK_MW8266D_UART_INTERFACE              USART1
#define ATK_MW8266D_UART_IRQn                   USART1_IRQn
#define ATK_MW8266D_UART_IRQHandler             USART1_IRQHandler
#define ATK_MW8266D_UART_CLK_ENABLE()           do{ __HAL_RCC_USART1_CLK_ENABLE(); }while(0)    /* USART3 时钟使能 */
#endif

#if 0
#define ATK_MW8266D_UART_TX_GPIO_PORT           GPIOC
#define ATK_MW8266D_UART_TX_GPIO_PIN            GPIO_PIN_10
#define ATK_MW8266D_UART_TX_GPIO_AF             GPIO_AF7_USART3
#define ATK_MW8266D_UART_TX_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)     /* PB口时钟使能 */

#define ATK_MW8266D_UART_RX_GPIO_PORT           GPIOD
#define ATK_MW8266D_UART_RX_GPIO_PIN            GPIO_PIN_9
#define ATK_MW8266D_UART_RX_GPIO_AF             GPIO_AF7_USART3
#define ATK_MW8266D_UART_RX_GPIO_CLK_ENABLE()   do{ __HAL_RCC_GPIOD_CLK_ENABLE(); }while(0)     /* PB口时钟使能 */

#define ATK_MW8266D_UART_INTERFACE              USART3
#define ATK_MW8266D_UART_IRQn                   USART3_IRQn
#define ATK_MW8266D_UART_IRQHandler             USART3_IRQHandler
#define ATK_MW8266D_UART_CLK_ENABLE()           do{ __HAL_RCC_USART3_CLK_ENABLE(); }while(0)    /* USART3 时钟使能 */
#endif
/* UART收发缓冲大小 */
#define ATK_MW8266D_UART_RX_BUF_SIZE            128
#define ATK_MW8266D_UART_TX_BUF_SIZE            64

/* 操作函数 */
void wifiprintf(char *fmt, ...);       /* ATK-MW8266D UART printf */
void atk_mw8266d_uart_rx_restart(void);             /* ATK-MW8266D UART重新开始接收数据 */
uint8_t *atk_mw8266d_uart_rx_get_frame(void);       /* 获取ATK-MW8266D UART接收到的一帧数据 */
uint16_t atk_mw8266d_uart_rx_get_frame_len(void);   /* 获取ATK-MW8266D UART接收到的一帧数据的长度 */
void atk_mw8266d_uart_init(uint32_t baudrate);      /* ATK-MW8266D UART初始化 */

#endif
