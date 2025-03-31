/*
 * leds.c
 *
 *  Created on: 2024��10��29��
 *      Author: Xianhao
 */

#include "leds.h"

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������         : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init(void)
{
    EALLOW;//�ر�д����
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // ����GPIOʱ��

    //LED1�˿�����
    GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//����Ϊͨ��GPIO����
    GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//����GPIO����Ϊ���
    GpioCtrlRegs.GPCPUD.bit.GPIO68=0;//ʹ��GPIO��������

    GpioDataRegs.GPCSET.bit.GPIO68=1;//����GPIO����ߵ�ƽ

    //LED2�˿�����
    GpioCtrlRegs.GPCMUX1.bit.GPIO67=0;//����Ϊͨ��GPIO����
    GpioCtrlRegs.GPCDIR.bit.GPIO67=1;//����GPIO����Ϊ���
    GpioCtrlRegs.GPCPUD.bit.GPIO67=0;//ʹ��GPIO��������

    GpioDataRegs.GPCSET.bit.GPIO67=1;//����GPIO����ߵ�ƽ

    //LED3�˿�����
    GpioCtrlRegs.GPCMUX1.bit.GPIO66=0;//����Ϊͨ��GPIO����
    GpioCtrlRegs.GPCDIR.bit.GPIO66=1;//����GPIO����Ϊ���
    GpioCtrlRegs.GPCPUD.bit.GPIO66=0;//ʹ��GPIO��������

    GpioDataRegs.GPCSET.bit.GPIO66=1;//����GPIO����ߵ�ƽ

    //LED4�˿�����
    GpioCtrlRegs.GPCMUX1.bit.GPIO65=0;
    GpioCtrlRegs.GPCDIR.bit.GPIO65=1;
    GpioCtrlRegs.GPCPUD.bit.GPIO65=0;

    GpioDataRegs.GPCSET.bit.GPIO65=1;//����GPIO����ߵ�ƽ

    //LED5�˿�����
    GpioCtrlRegs.GPCMUX1.bit.GPIO64=0;
    GpioCtrlRegs.GPCDIR.bit.GPIO64=1;
    GpioCtrlRegs.GPCPUD.bit.GPIO64=0;

    GpioDataRegs.GPCSET.bit.GPIO64=1;//����GPIO����ߵ�ƽ

    //LED6�˿�����
    GpioCtrlRegs.GPAMUX1.bit.GPIO10=0;
    GpioCtrlRegs.GPADIR.bit.GPIO10=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO10=0;

    GpioDataRegs.GPASET.bit.GPIO10=1;//����GPIO����ߵ�ƽ

    //LED7�˿�����
    GpioCtrlRegs.GPAMUX1.bit.GPIO11=0;
    GpioCtrlRegs.GPADIR.bit.GPIO11=1;
    GpioCtrlRegs.GPAPUD.bit.GPIO11=0;

    GpioDataRegs.GPASET.bit.GPIO11=1;//����GPIO����ߵ�ƽ

//    GpioCtrlRegs.GPAMUX2.bit.GPIO20=0;
//    GpioCtrlRegs.GPADIR.bit.GPIO20=1;
//    GpioCtrlRegs.GPAPUD.bit.GPIO20=0;
//
//    GpioDataRegs.GPASET.bit.GPIO20=1;//����GPIO����ߵ�ƽ
//
//    GpioCtrlRegs.GPAMUX2.bit.GPIO21=0;
//    GpioCtrlRegs.GPADIR.bit.GPIO21=1;
//    GpioCtrlRegs.GPAPUD.bit.GPIO21=0;
//
//    GpioDataRegs.GPASET.bit.GPIO21=1;//����GPIO����ߵ�ƽ

    EDIS;//����д����
}
