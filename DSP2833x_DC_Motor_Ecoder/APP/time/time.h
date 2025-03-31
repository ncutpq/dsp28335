/*
 * time.h
 *
 *  Created on: 2025年2月25日
 *      Author: Xianhao
 */

#ifndef APP_TIME_TIME_H_
#define APP_TIME_TIME_H_

#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件

void TIM0_Init(float Freq, float Period);

interrupt void TIM0_IRQn(void);

#endif /* APP_TIME_TIME_H_ */
