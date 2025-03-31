/*
 * dc_motor.c
 *
 *  Created on: 2024��10��30��
 *      Author: Xianhao
 */

#include "dc_motor.h"
#include "epwm.h"

void DC_Motor_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;  //����GPIOʱ��

    //DC_MOTOR ��1·�˿�����
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;

    //DC_MOTOR ��2·�˿�����
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 1;

    EDIS;
    GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;
}

float my_abs(float num)
{
    if (num < 0.0)
        return -num; // ����Ǹ������������෴��
    else
        return num;  // ������������㣬ֱ�ӷ���
}

void Motor_SetSpeed(float Speed)
{
    if (Speed >= 0.0)
    {
        DC_MOTOR_INA_SETH;
        DC_MOTOR_INB_SETL;
    }
    else
    {
        DC_MOTOR_INA_SETL;
        DC_MOTOR_INB_SETH;
    }
    EPwm1B_SetCompare(my_abs(Speed));
}
