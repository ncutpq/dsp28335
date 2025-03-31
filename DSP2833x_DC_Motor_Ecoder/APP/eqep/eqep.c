/*
 * eqep.c
 *
 *  Created on: 2025��2��25��
 *      Author: Xianhao
 */

#include "eqep.h"
#include "uart.h"
#include "smg.h"

Uint16 delay_show=0;
Uint16 DirectionQep=0;
Uint16 Encoder_N=11*4; //�����ת1Ȧ�����������(ͨ����Ҫ4��Ƶ)
Uint16 motor_speed=0;
Uint32 Speed_Mr_RPM=0;
Uint32 Position_k_1=0;
Uint32 Position_k=0;

void EQEP2_Init(void)
{
    // ���� eQEP2 ʱ��
    EALLOW;
    SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;
    EDIS;

    #if(CPU_FRQ_150MHZ)
        EQep2Regs.QUPRD=1500000;//��SYSCLKOUT=150MHZʱ���趨Unit Timer
                                //���Ƶ��Ϊ1000HZ
    #endif
    #if(CPU_FRQ_100MHZ)
        EQep2Regs.QUPRD=100000;//��SYSCLKOUT=100MHZʱ���趨Unit Timer
                                //���Ƶ��Ϊ1000HZ
    #endif
    EQep2Regs.QDECCTL.bit.QSRC=0;//����eQEP����ģʽ
    EQep2Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep2Regs.QEPCTL.bit.PCRM=00;//�趨PCRM=00����QPOSCNT��ÿ��Index ���嶼��λ     ****��ʼ00
    EQep2Regs.QEPCTL.bit.UTE=1;//ʹ��UTE��Ԫ�������
    EQep2Regs.QEPCTL.bit.QCLM=1;//��UTE��Ԫ���ʱ��������
    EQep2Regs.QEPCTL.bit.QPEN=1;//ʹ��eQEP
    EQep2Regs.QCAPCTL.bit.UPPS=5;//1/32 for unit position
    EQep2Regs.QCAPCTL.bit.CCPS=7;//1/128 for CAP clock
    EQep2Regs.QCAPCTL.bit.CEN=1;//ʹ��eQEP�Ĳ�����                     *****��ʼ1
    EQep2Regs.QPOSMAX=Encoder_N;//�趨�����������ֵ
    EQep2Regs.QEPCTL.bit.SWI=1;//���ǿ�Ʋ���һ��index����
    InitEQep2Gpio();

}


//void EQEP2_Init(void)
//{
//    // ���� eQEP2 ʱ��
//    EALLOW;
//    SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;
//    EDIS;
//
//    EQep2Regs.QUPRD=1500000; //��SYSCLKOUT=150MHZʱ���趨Unit Timer
//    EQep2Regs.QPOSMAX=10000; //λ�ü����������ֵ,ͨ������Ϊ�����תһȦ����ı���������
//
//    EQep2Regs.QDECCTL.bit.QSRC=0;//����eQEPΪ��������ģʽ
//
//    EQep2Regs.QEPCTL.bit.UTE=1;//ʹ�ܵ�λʱ���¼�(UTE)��Ԫ�������
//
//    EQep2Regs.QEPCTL.bit.QCLM=1;//����λʱ���¼�����ʱ��������
//
//    EQep2Regs.QEPCTL.bit.QPEN=1;//ʹ��eQEP
//
//    InitEQep2Gpio();
//}

float get_encoder_val(void)
{
    Uint32 tmp1=0;
    delay_show++;

    //������ת����
    DirectionQep=EQep2Regs.QEPSTS.bit.QDF;

    //��������ź�
    if(EQep2Regs.QFLG.bit.IEL==1)
    {
        EQep2Regs.QCLR.bit.IEL=1;//����ж��ź�
    }

    if(EQep2Regs.QFLG.bit.UTO==1)//������λʱ���¼��������ʱ����׼��Ԫ��������¼� 0.001�ж�һ��
    {
        Position_k_1= EQep2Regs.QPOSLAT;//��ȡ��ǰλ��
        if(DirectionQep==0)//POSCNT is counting down
        {
            if(Position_k >= Position_k_1)
                tmp1=Position_k - Position_k_1;//��ǰλ�û�û�й���
            else
                tmp1=Encoder_N+(Position_k - Position_k_1);//��ǰλ���ѹ���
        }
        else if(DirectionQep==1)//POSCNT is counting up
        {
            if(Position_k <= Position_k_1)
                tmp1=Position_k_1 - Position_k;//��ǰλ�û�û�й���
            else
                tmp1=Encoder_N+(Position_k_1 - Position_k);//��ǰλ���ѹ���
        }
        Speed_Mr_RPM= tmp1*60/(Encoder_N*37*0.001);//ת/����
        Position_k=Position_k_1;//������һ��λ��
        EQep2Regs.QCLR.bit.UTO=1;
        if (delay_show % 100 == 0) {
            motor_speed = (Uint16)Speed_Mr_RPM; // ת��Ϊ����
            printf("speed:%d\r\n",motor_speed);
            delay_show = 0; // ���ü�����
        }
    }
    return Speed_Mr_RPM;
//    return tmp1; // ֱ�ӷ���������
}

