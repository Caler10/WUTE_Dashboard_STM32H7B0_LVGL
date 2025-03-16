//��1ʹ�ܸ�������/�ű���
#if 1


#include "usart.h"
#include "myusart.h"

#define TX_BUF_LEN  256     /* ���ͻ�����������������Ҫ���е��� */  //ԭ256����Ϊ����͸������ֻҪ64�͹��ˣ�so
uint8_t TxBuf[TX_BUF_LEN];  // ���ͻ�����

/*****************************��ֹ����������������******************************/

#if 1
#if (__ARMCC_VERSION >= 6010050)            /* ʹ��AC6������ʱ */
__asm(".global __use_no_semihosting\n\t");  /* ������ʹ�ð�����ģʽ */
__asm(".global __ARM_use_no_argv \n\t");    /* AC6����Ҫ����main����Ϊ�޲�����ʽ�����򲿷����̿��ܳ��ְ�����ģʽ */

#else
/* ʹ��AC5������ʱ, Ҫ�����ﶨ��__FILE �� ��ʹ�ð�����ģʽ */
#pragma import(__use_no_semihosting)

struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
};

#endif

/* ��ʹ�ð�����ģʽ��������Ҫ�ض���_ttywrch\_sys_exit\_sys_command_string����,��ͬʱ����AC6��AC5ģʽ */
int _ttywrch(int ch)
{
    ch = ch;
    return ch;
}

/* ����_sys_exit()�Ա���ʹ�ð�����ģʽ */
void _sys_exit(int x)
{
    x = x;
}

char *_sys_command_string(char *cmd, int len)
{
    return NULL;
}

/* FILE �� stdio.h���涨��. */
FILE __stdout;

/* �ض���fputc����, printf�������ջ�ͨ������fputc����ַ��������� */
int fputc(int ch, FILE *f)
{
    while ((USART1->ISR & 0X40) == 0);    /* �ȴ���һ���ַ�������� */

    USART1->TDR = (uint8_t)ch;            /* ��Ҫ���͵��ַ� ch д�뵽DR�Ĵ��� */
    return ch;
}
#endif
/********************************��ֹ����������********************************/


//����һ���Լ�д��ӡ���� ������printf����
//���ǻ������������Ϊ����printf������������ˡ�stdio.h�����Ա��벻�ᱨ����δ�ض���δ��ֹ�����������������������ڴ�ӡ������
void myprintf(const char *__format, ...)
{
  va_list ap;
  va_start(ap, __format);
  
  /* ��շ��ͻ����� */
  memset(TxBuf, 0x0, TX_BUF_LEN);
  
  /* ��䷢�ͻ����� */
  vsnprintf((char*)TxBuf, TX_BUF_LEN, (const char *)__format, ap);
  va_end(ap);
  int len = strlen((const char*)TxBuf);
  
  /* �����ڷ������� */
  HAL_UART_Transmit(&huart1, (uint8_t*)&TxBuf, len, 0xFFFF);
}



//������������printf���� 1.�ض��� 2.ʹ��microLIB����߽�ֹ������״̬���ĵ�������β���������δ�ɹ���������6��������ԭ��ATKESP8266����͸��ʵ���÷�ʽ2�ñ�����6���Գɹ���
//��ڲ���:	ch - Ҫ������ַ� ��  f - �ļ�ָ�루�����ò�����
//�� �� ֵ:	����ʱ�����ַ�������ʱ���� EOF��-1��
//��������:	�ض��� fputc ������Ŀ����ʹ�� printf ����

//int fputc(int ch, FILE *f)
//{
//	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 100);	// ���͵��ֽ�����
//	return (ch);
//}


//��������ѡ��use MicroLIB���ض���ʹ��printf


#endif