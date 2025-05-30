#if 1


/**
 ****************************************************************************************************
 * @file        demo.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2022-06-21
 * @brief       ATK-MW8266D模块TCP透传实验
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

#include "wifiapp.h"
#include "atk_mw8266d.h"
#include "yzusart.h"   //原子的串口打印接收驱动包
//#include "./SYSTEM/delay/delay.h"
//#include "./BSP/LED/led.h"
//#include "./BSP/KEY/key.h"
//#include "./BSP/LCD/lcd.h"
#include "led_bottun.h"

#define DEMO_WIFI_SSID          "E33PANEL"   //"ALIENTEK-YF"
#define DEMO_WIFI_PWD           "15902020"   //"15902020353"
#define DEMO_TCP_SERVER_IP      "192.168.43.13"     //"192.168.1.3"
#define DEMO_TCP_SERVER_PORT    "8080"

/**
 * @brief       显示IP地址
 * @param       无
 * @retval      无
 */
static void demo_show_ip(char *buf)
{
    printf("IP: %s\r\n", buf);
//    lcd_show_string(60, 151, 128, 16, 16, buf, BLUE);
}

/**
 * @brief       按键0功能，功能测试
 * @param       is_unvarnished: 0，未进入透传
 *                              1，已进入透传
 * @retval      无
 */
static void demo_key0_fun(uint8_t is_unvarnished)
{
    uint8_t ret;
    
    if (is_unvarnished == 0)
    {
        /* 进行AT指令测试 */
        ret = atk_mw8266d_at_test();
        if (ret == 0)
        {
            printf("AT test success!\r\n");
        }
        else
        {
            printf("AT test failed!\r\n");
        }
    }
    else
    {
        /* 通过透传，发送信息至TCP Server */
        printf("This ATK-MW8266D TCP Connect Test.\r\n");
    }
}

/**
 * @brief       按键1功能，切换透传模式
 * @param       is_unvarnished: 0，未进入透传
 *                              1，已进入透传
 * @retval      无
 */
static void demo_key1_fun(uint8_t *is_unvarnished)
{
    uint8_t ret;
    
    if (*is_unvarnished == 0)
    {
        /* 进入透传 */
        ret = atk_mw8266d_enter_unvarnished();
        if (ret == 0)
        {
            *is_unvarnished = 1;
            printf("Enter unvarnished!\r\n");
        }
        else
        {
            printf("Enter unvarnished failed!\r\n");
        }
    }
    else
    {
        /* 退出透传 */
        atk_mw8266d_exit_unvarnished();
        *is_unvarnished = 0;
        printf("Exit unvarnished!\r\n");
    }
}

/**
 * @brief       进入透传时，将接收自TCP Server的数据发送到串口调试助手
 * @param       is_unvarnished: 0，未进入透传
 *                              1，已进入透传
 * @retval      无
 */
static void demo_upload_data(uint8_t is_unvarnished)
{
    uint8_t *buf;
    
    if (is_unvarnished == 1)
    {
        /* 接收来自ATK-MW8266D UART的一帧数据 */
        buf = atk_mw8266d_uart_rx_get_frame();
        if (buf != NULL)
        {
            printf("%s", buf);
            /* 重开开始接收来自ATK-MW8266D UART的数据 */
            atk_mw8266d_uart_rx_restart();
        }
    }
}





/**
 * @brief       例程演示入口函数
 * @param       无
 * @retval      无
 */
void wifi_run(void)
{
    uint8_t ret;
    char ip_buf[16];
    uint8_t key;
    uint8_t is_unvarnished = 0;
    
    /* 初始化ATK-MW8266D */
    ret = atk_mw8266d_init(115200);
    if (ret == 0)
    {
        printf("ATK-MW8266D init finish!\r\n");
//        while (1)
//        {
////            LED0_TOGGLE();
//            HAL_Delay(200);
//        }
    
    
    printf("Joining to AP...\r\n");
    ret  = atk_mw8266d_restore();                               /* 恢复出厂设置 */
    ret += atk_mw8266d_at_test();                               /* AT测试 */
    ret += atk_mw8266d_set_mode(1);                             /* Station模式 */
    ret += atk_mw8266d_sw_reset();                              /* 软件复位 */
    ret += atk_mw8266d_ate_config(0);                           /* 关闭回显功能 */
    ret += atk_mw8266d_join_ap(DEMO_WIFI_SSID, DEMO_WIFI_PWD);  /* 连接WIFI */
    ret += atk_mw8266d_get_ip(ip_buf);                          /* 获取IP地址 */
    if (ret != 0)
    {
        printf("Error to join ap!\r\n");
        while (1)
        {
//            LED0_TOGGLE();
            HAL_Delay(200);
        }
    }
    demo_show_ip(ip_buf);
    
    /* 连接TCP服务器 */
    ret = atk_mw8266d_connect_tcp_server(DEMO_TCP_SERVER_IP, DEMO_TCP_SERVER_PORT);
    if (ret != 0)
    {
        printf("Error to connect tcp server!\r\n");
        while (1)
        {
//            LED0_TOGGLE();
            HAL_Delay(200);
        }
    }
    printf("link to TCP Server!\r\n");

    /* 重新开始接收新的一帧数据 */
//    atk_mw8266d_uart_rx_restart();
//    
//    while (1)
//    {
//        key = key_scan(0);
//        
//        switch (key)
//        {
//            case KEY0_PRES:
//            {
//                /* 功能测试 */
//                demo_key0_fun(is_unvarnished);
//                break;
//            }
//            case KEY1_PRES:
//            {
//                /* 透传模式切换 */
//                demo_key1_fun(&is_unvarnished);
//                break;
//            }
//            default:
//            {
//                break;
//            }
//        }
//        
//        /* 发送透传接收自TCP Server的数据到串口调试助手 */
//        demo_upload_data(is_unvarnished);
//        
//        HAL_Delay(10);
//    }
		atk_mw8266d_enter_unvarnished();
		printf("Enter unvarnished!\r\n");
	}//如果初始化就失败
}


#endif