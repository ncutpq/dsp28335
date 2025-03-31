/*
 * eqep.h
 *
 *  Created on: 2025年2月25日
 *      Author: Xianhao
 */

#ifndef APP_EQEP_EQEP_H_
#define APP_EQEP_EQEP_H_

#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件

void EQEP2_Init(void);
//int32 Encoder_Get(void);
float get_encoder_val(void);
//int16 Encoder_Get(void);
#endif /* APP_EQEP_EQEP_H_ */
