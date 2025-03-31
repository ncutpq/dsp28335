/*
 * eqep.c
 *
 *  Created on: 2025年2月25日
 *      Author: Xianhao
 */

#include "eqep.h"
#include "uart.h"
#include "smg.h"

Uint16 delay_show=0;
Uint16 DirectionQep=0;
Uint16 Encoder_N=11*4; //电机旋转1圈所需的脉冲数(通常还要4倍频)
Uint16 motor_speed=0;
Uint32 Speed_Mr_RPM=0;
Uint32 Position_k_1=0;
Uint32 Position_k=0;

void EQEP2_Init(void)
{
    // 启用 eQEP2 时钟
    EALLOW;
    SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;
    EDIS;

    #if(CPU_FRQ_150MHZ)
        EQep2Regs.QUPRD=1500000;//当SYSCLKOUT=150MHZ时，设定Unit Timer
                                //溢出频率为1000HZ
    #endif
    #if(CPU_FRQ_100MHZ)
        EQep2Regs.QUPRD=100000;//当SYSCLKOUT=100MHZ时，设定Unit Timer
                                //溢出频率为1000HZ
    #endif
    EQep2Regs.QDECCTL.bit.QSRC=0;//设置eQEP计数模式
    EQep2Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep2Regs.QEPCTL.bit.PCRM=00;//设定PCRM=00，即QPOSCNT在每次Index 脉冲都复位     ****初始00
    EQep2Regs.QEPCTL.bit.UTE=1;//使能UTE单元溢出功能
    EQep2Regs.QEPCTL.bit.QCLM=1;//当UTE单元溢出时允许锁存
    EQep2Regs.QEPCTL.bit.QPEN=1;//使能eQEP
    EQep2Regs.QCAPCTL.bit.UPPS=5;//1/32 for unit position
    EQep2Regs.QCAPCTL.bit.CCPS=7;//1/128 for CAP clock
    EQep2Regs.QCAPCTL.bit.CEN=1;//使能eQEP的捕获功能                     *****初始1
    EQep2Regs.QPOSMAX=Encoder_N;//设定计数器的最大值
    EQep2Regs.QEPCTL.bit.SWI=1;//软件强制产生一次index脉冲
    InitEQep2Gpio();

}


//void EQEP2_Init(void)
//{
//    // 启用 eQEP2 时钟
//    EALLOW;
//    SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;
//    EDIS;
//
//    EQep2Regs.QUPRD=1500000; //当SYSCLKOUT=150MHZ时，设定Unit Timer
//    EQep2Regs.QPOSMAX=10000; //位置计数器的最大值,通常设置为电机旋转一圈所需的编码脉冲数
//
//    EQep2Regs.QDECCTL.bit.QSRC=0;//设置eQEP为正交计数模式
//
//    EQep2Regs.QEPCTL.bit.UTE=1;//使能单位时间事件(UTE)单元溢出功能
//
//    EQep2Regs.QEPCTL.bit.QCLM=1;//当单位时间事件发生时允许锁存
//
//    EQep2Regs.QEPCTL.bit.QPEN=1;//使能eQEP
//
//    InitEQep2Gpio();
//}

float get_encoder_val(void)
{
    Uint32 tmp1=0;
    delay_show++;

    //解码旋转方向
    DirectionQep=EQep2Regs.QEPSTS.bit.QDF;

    //检测索引信号
    if(EQep2Regs.QFLG.bit.IEL==1)
    {
        EQep2Regs.QCLR.bit.IEL=1;//清除中断信号
    }

    if(EQep2Regs.QFLG.bit.UTO==1)//发生单位时间事件，如果定时器基准单元出现溢出事件 0.001中断一次
    {
        Position_k_1= EQep2Regs.QPOSLAT;//获取当前位置
        if(DirectionQep==0)//POSCNT is counting down
        {
            if(Position_k >= Position_k_1)
                tmp1=Position_k - Position_k_1;//当前位置还没有过零
            else
                tmp1=Encoder_N+(Position_k - Position_k_1);//当前位置已过零
        }
        else if(DirectionQep==1)//POSCNT is counting up
        {
            if(Position_k <= Position_k_1)
                tmp1=Position_k_1 - Position_k;//当前位置还没有过零
            else
                tmp1=Encoder_N+(Position_k_1 - Position_k);//当前位置已过零
        }
        Speed_Mr_RPM= tmp1*60/(Encoder_N*37*0.001);//转/分钟
        Position_k=Position_k_1;//更新上一次位置
        EQep2Regs.QCLR.bit.UTO=1;
        if (delay_show % 100 == 0) {
            motor_speed = (Uint16)Speed_Mr_RPM; // 转换为整数
            printf("speed:%d\r\n",motor_speed);
            delay_show = 0; // 重置计数器
        }
    }
    return Speed_Mr_RPM;
//    return tmp1; // 直接返回脉冲数
}

