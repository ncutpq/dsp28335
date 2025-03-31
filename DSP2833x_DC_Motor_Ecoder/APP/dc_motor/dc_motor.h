/*
 * dc_motor.h
 *
 *  Created on: 2024Äê10ÔÂ30ÈÕ
 *      Author: Xianhao
 */

#ifndef APP_DC_MOTOR_DC_MOTOR_H_
#define APP_DC_MOTOR_DC_MOTOR_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define DC_MOTOR_INA_SETH    (GpioDataRegs.GPASET.bit.GPIO2 = 1)
#define DC_MOTOR_INA_SETL    (GpioDataRegs.GPACLEAR.bit.GPIO2 = 1)
#define DC_MOTOR_INB_SETH    (GpioDataRegs.GPASET.bit.GPIO3 = 1)
#define DC_MOTOR_INB_SETL    (GpioDataRegs.GPACLEAR.bit.GPIO3 = 1)

#define DC_MOTOR_INC_SETH    (GpioDataRegs.GPASET.bit.GPIO4 = 1)
#define DC_MOTOR_INC_SETL    (GpioDataRegs.GPACLEAR.bit.GPIO4 = 1)
#define DC_MOTOR_IND_SETH    (GpioDataRegs.GPASET.bit.GPIO5 = 1)
#define DC_MOTOR_IND_SETL    (GpioDataRegs.GPACLEAR.bit.GPIO5 = 1)

void DC_Motor_Init(void);
void Motor_SetSpeed(float Speed);

#endif /* APP_DC_MOTOR_DC_MOTOR_H_ */
