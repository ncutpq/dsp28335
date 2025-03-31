/*
 * leds.c
 *
 *  Created on: 2024年10月29日
 *      Author: Xianhao
 */

#include "leds.h"

/*******************************************************************************
* 函 数 名         : LED_Init
* 函数功能         : LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init(void)
{
    EALLOW;//关闭写保护
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // 开启GPIO时钟

    //LED1端口配置
    GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//设置为通用GPIO功能
    GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//设置GPIO方向为输出
    GpioCtrlRegs.GPCPUD.bit.GPIO68=0;//使能GPIO上拉电阻

    GpioDataRegs.GPCSET.bit.GPIO68=1;//设置GPIO输出高电平

    //LED2端口配置
    GpioCtrlRegs.GPCMUX1.bit.GPIO67=0;//设置为通用GPIO功能
    GpioCtrlRegs.GPCDIR.bit.GPIO67=1;//设置GPIO方向为输出
    GpioCtrlRegs.GPCPUD.bit.GPIO67=0;//使能GPIO上拉电阻

    GpioDataRegs.GPCSET.bit.GPIO67=1;//设置GPIO输出高电平

    //LED3端口配置
    GpioCtrlRegs.GPCMUX1.bit.GPIO66=0;//设置为通用GPIO功能
    GpioCtrlRegs.GPCDIR.bit.GPIO66=1;//设置GPIO方向为输出
    GpioCtrlRegs.GPCPUD.bit.GPIO66=0;//使能GPIO上拉电阻

    GpioDataRegs.GPCSET.bit.GPIO66=1;//设置GPIO输出高电平

    //LED4端口配置
    GpioCtrlRegs.GPCMUX1.bit.GPIO65=0;
    GpioCtrlRegs.GPCDIR.bit.GPIO65=1;
    GpioCtrlRegs.GPCPUD.bit.GPIO65=0;

    GpioDataRegs.GPCSET.bit.GPIO65=1;//设置GPIO输出高电平

    //LED5端口配置
    GpioCtrlRegs.GPCMUX1.bit.GPIO64=0;
    GpioCtrlRegs.GPCDIR.bit.GPIO64=1;
    GpioCtrlRegs.GPCPUD.bit.GPIO64=0;

    GpioDataRegs.GPCSET.bit.GPIO64=1;//设置GPIO输出高电平

    //LED6端口配置
    GpioCtrlRegs.GPAMUX1.bit.GPIO10=0;
    GpioCtrlRegs.GPADIR.bit.GPIO10=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO10=0;

    GpioDataRegs.GPASET.bit.GPIO10=1;//设置GPIO输出高电平

    //LED7端口配置
    GpioCtrlRegs.GPAMUX1.bit.GPIO11=0;
    GpioCtrlRegs.GPADIR.bit.GPIO11=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO11=0;

    GpioDataRegs.GPASET.bit.GPIO11=1;//设置GPIO输出高电平

//    GpioCtrlRegs.GPAMUX2.bit.GPIO20=0;
//    GpioCtrlRegs.GPADIR.bit.GPIO20=1;
//    GpioCtrlRegs.GPAPUD.bit.GPIO20=0;
//
//    GpioDataRegs.GPASET.bit.GPIO20=1;//设置GPIO输出高电平
//
//    GpioCtrlRegs.GPAMUX2.bit.GPIO21=0;
//    GpioCtrlRegs.GPADIR.bit.GPIO21=1;
//    GpioCtrlRegs.GPAPUD.bit.GPIO21=0;
//
//    GpioDataRegs.GPASET.bit.GPIO21=1;//设置GPIO输出高电平

    EDIS;//开启写保护
}
