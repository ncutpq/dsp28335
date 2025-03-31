/*
 * relay.h
 *
 *  Created on: 2024Äê10ÔÂ30ÈÕ
 *      Author: Xianhao
 */

#ifndef APP_RELAY_RELAY_H_
#define APP_RELAY_RELAY_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define RELAY_ON      (GpioDataRegs.GPASET.bit.GPIO15 = 1)
#define RELAY_OFF     (GpioDataRegs.GPACLEAR.bit.GPIO15 = 1)

void Relay_Init(void);

#endif /* APP_RELAY_RELAY_H_ */
