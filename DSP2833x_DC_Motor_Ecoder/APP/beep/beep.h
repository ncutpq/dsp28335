/*
 * beep.h
 *
 *  Created on: 2024Äê10ÔÂ30ÈÕ
 *      Author: Xianhao
 */

#ifndef APP_BEEP_BEEP_H_
#define APP_BEEP_BEEP_H_


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define BEEP_ON      (GpioDataRegs.GPASET.bit.GPIO6 = 1)
#define BEEP_OFF     (GpioDataRegs.GPACLEAR.bit.GPIO6 = 1)
#define BEEP_TOGGLE  (GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1)

void BEEP_Init(void);


#endif /* APP_BEEP_BEEP_H_ */
