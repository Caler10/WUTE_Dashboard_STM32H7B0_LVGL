//置1使能该驱动库/脚本库
#if 1


#include "usart.h"
#include "myusart.h"

#define TX_BUF_LEN  256     /* 发送缓冲区容量，根据需要进行调整 */  //原256，因为无线透传例程只要64就够了，so
uint8_t TxBuf[TX_BUF_LEN];  // 发送缓冲区

/*****************************禁止半主机（方案二）******************************/

#if 1
#if (__ARMCC_VERSION >= 6010050)            /* 使用AC6编译器时 */
__asm(".global __use_no_semihosting\n\t");  /* 声明不使用半主机模式 */
__asm(".global __ARM_use_no_argv \n\t");    /* AC6下需要声明main函数为无参数格式，否则部分例程可能出现半主机模式 */

#else
/* 使用AC5编译器时, 要在这里定义__FILE 和 不使用半主机模式 */
#pragma import(__use_no_semihosting)

struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
};

#endif

/* 不使用半主机模式，至少需要重定义_ttywrch\_sys_exit\_sys_command_string函数,以同时兼容AC6和AC5模式 */
int _ttywrch(int ch)
{
    ch = ch;
    return ch;
}

/* 定义_sys_exit()以避免使用半主机模式 */
void _sys_exit(int x)
{
    x = x;
}

char *_sys_command_string(char *cmd, int len)
{
    return NULL;
}

/* FILE 在 stdio.h里面定义. */
FILE __stdout;

/* 重定义fputc函数, printf函数最终会通过调用fputc输出字符串到串口 */
int fputc(int ch, FILE *f)
{
    while ((USART1->ISR & 0X40) == 0);    /* 等待上一个字符发送完成 */

    USART1->TDR = (uint8_t)ch;            /* 将要发送的字符 ch 写入到DR寄存器 */
    return ch;
}
#endif
/********************************禁止半主机结束********************************/


//方案一：自己写打印函数 不基于printf函数
//还是会进半主机？因为用了printf残留，因调用了“stdio.h”所以编译不会报错，但未重定向未禁止半主机，进半主机，还串口打印不出来
void myprintf(const char *__format, ...)
{
  va_list ap;
  va_start(ap, __format);
  
  /* 清空发送缓冲区 */
  memset(TxBuf, 0x0, TX_BUF_LEN);
  
  /* 填充发送缓冲区 */
  vsnprintf((char*)TxBuf, TX_BUF_LEN, (const char *)__format, ap);
  va_end(ap);
  int len = strlen((const char*)TxBuf);
  
  /* 往串口发送数据 */
  HAL_UART_Transmit(&huart1, (uint8_t*)&TxBuf, len, 0xFFFF);
}



//方案二：基于printf函数 1.重定向 2.使用microLIB库或者禁止半主机状态（文档里有如何操作，但还未成功（编译器6），正点原子ATKESP8266串口透传实验用方式2用编译器6可以成功）
//入口参数:	ch - 要输出的字符 ，  f - 文件指针（这里用不到）
//返 回 值:	正常时返回字符，出错时返回 EOF（-1）
//函数功能:	重定向 fputc 函数，目的是使用 printf 函数

//int fputc(int ch, FILE *f)
//{
//	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 100);	// 发送单字节数据
//	return (ch);
//}


//方案三：选择use MicroLIB，重定向，使用printf


#endif