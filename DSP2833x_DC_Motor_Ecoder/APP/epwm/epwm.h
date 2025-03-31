/*
 * epwm.h
 *
 *  Created on: 2025��2��25��
 *      Author: Xianhao
 */

#ifndef APP_EPWM_EPWM_H_
#define APP_EPWM_EPWM_H_

#include "DSP2833x_Device.h"     // DSP2833x ͷ�ļ�
#include "DSP2833x_Examples.h"   // DSP2833x �������ͷ�ļ�

void EPWM1_Init(Uint16 tbprd);
void EPwm1A_SetCompare(Uint16 val);
void EPwm1B_SetCompare(Uint16 val);
interrupt void epwm1_tzint_isr(void);

#endif /* APP_EPWM_EPWM_H_ */
