/*
 * relay.c
 *
 *  Created on: 2024��10��30��
 *      Author: Xianhao
 */

#include "relay.h"

void Relay_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;   //����GPIOʱ��

    //�̵����˿�����
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;

    EDIS;
    GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;

}
