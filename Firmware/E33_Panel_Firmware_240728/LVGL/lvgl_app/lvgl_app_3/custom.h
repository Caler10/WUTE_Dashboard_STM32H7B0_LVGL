// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"


void custom_init(lv_ui *ui);
void updata_task1_callback(lv_timer_t *tmr);//任务回调函数
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
