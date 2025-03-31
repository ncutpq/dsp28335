/*
 * time.h
 *
 *  Created on: 2025��2��25��
 *      Author: Xianhao
 */

#ifndef APP_TIME_TIME_H_
#define APP_TIME_TIME_H_

#include "DSP2833x_Device.h"     // DSP2833x ͷ�ļ�
#include "DSP2833x_Examples.h"   // DSP2833x �������ͷ�ļ�

void TIM0_Init(float Freq, float Period);

interrupt void TIM0_IRQn(void);

#endif /* APP_TIME_TIME_H_ */
