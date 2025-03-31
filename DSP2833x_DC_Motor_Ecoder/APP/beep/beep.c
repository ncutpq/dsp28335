/*
 * beep.c
 *
 *  Created on: 2024年10月30日
 *      Author: Xianhao
 */

#include "beep.h"


void BEEP_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;  //开启GPIO时钟
    //BEEP端口配置
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;

    EDIS;
    GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
}
