#ifndef __LED_BOTTUN_H
#define __LED_BOTTUN_H

#include "main.h"

#define KEY0_PRES    1                  /* KEY0按下 */
#define KEY1_PRES    2                  /* KEY1按下 */
#define KEY2_PRES    3                  /* KEY2按下 */
#define WKUP_PRES    4                  /* KEY_UP按下(即WK_UP) */

uint8_t key_scan(uint8_t botton);//那个按键按下，返回什么值

#endif