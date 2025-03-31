/*
 * uart.c
 *
 *  Created on: 2025��2��25��
 *      Author: Xianhao
 */



#include "uart.h"


void UARTa_Init(Uint32 baud)
{
    unsigned char scihbaud=0;
    unsigned char scilbaud=0;
    Uint16 scibaud=0;

    scibaud=37500000/(8*baud)-1;
    scihbaud=scibaud>>8;
    scilbaud=scibaud&0xff;


    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;   // SCI-A
    EDIS;

    InitSciaGpio();

    //Initalize the SCI FIFO
    SciaRegs.SCIFFTX.all=0xE040;
    SciaRegs.SCIFFRX.all=0x204f;
    SciaRegs.SCIFFCT.all=0x0;

    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function
    SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
    SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE
    SciaRegs.SCICTL2.all =0x0003;
    SciaRegs.SCICTL2.bit.TXINTENA =1;
    SciaRegs.SCICTL2.bit.RXBKINTENA =1;
    SciaRegs.SCIHBAUD    =scihbaud;  // 9600 baud @LSPCLK = 37.5MHz.
    SciaRegs.SCILBAUD    =scilbaud;
//  SciaRegs.SCICCR.bit.LOOPBKENA =1; // Enable loop back
    SciaRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset

}


// Transmit a character from the SCI'
void UARTa_SendByte(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0);
    SciaRegs.SCITXBUF=a;
}

void UARTa_SendString(char * msg)
{
    int i=0;

    while(msg[i] != '\0')
    {
        UARTa_SendByte(msg[i]);
        i++;
    }
}

// ������ת��Ϊ�ַ���
void IntToString(Uint32 num, char *buffer) {
    int i = 0;
    int j = 0;
    char temp[12];  // ��ʱ������

    // �������� 0
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    // �����ֵ�ÿһλת��Ϊ�ַ�
    while (num > 0) {
        temp[i++] = (num % 10) + '0';  // ȡ���һλ��ת��Ϊ�ַ�
        num /= 10;  // ȥ�����һλ
    }

    // ��ת�ַ���
    while (i > 0) {
        buffer[j++] = temp[--i];
    }

    buffer[j] = '\0';  // ����ַ���������
}

// �򻯰� printf ��������֧�� %d��
void printf(const char *format, Uint32 num) {
    char buffer[32];  // ���������ڴ洢��ʽ������ַ���
    char ch;

    while ((ch = *format++) != '\0') {
        if (ch == '%' && *format == 'd') {
            format++;  // ���� 'd'
            IntToString(num, buffer);  // ������ת��Ϊ�ַ���
            UARTa_SendString(buffer);  // �����ַ���
        } else {
            UARTa_SendByte(ch);  // ������ͨ�ַ�
        }
    }
}
//
//// �򻯰� printf ��������֧�� %d, %s, %c��
//void printf(const char *format, Uint32 arg1, Uint32 arg2, Uint32 arg3) {
//    char buffer[32];  // ���������ڴ洢��ʽ������ַ���
//    char ch;
//    Uint8 argIndex = 0;  // ��������
//
//    while ((ch = *format++) != '\0') {
//        if (ch == '%') {
//            ch = *format++;  // ��ȡ��ʽ�ַ�
//            switch (ch) {
//                case 'd': {  // ����
//                    Uint32 num = (argIndex == 0) ? arg1 : (argIndex == 1) ? arg2 : arg3;
//                    IntToString(num, buffer);
//                    UARTa_SendString(buffer);
//                    argIndex++;
//                    break;
//                }
//                case 's': {  // �ַ���
//                    char *str = (argIndex == 0) ? (char *)arg1 : (argIndex == 1) ? (char *)arg2 : (char *)arg3;
//                    UARTa_SendString(str);
//                    argIndex++;
//                    break;
//                }
//                case 'c': {  // �ַ�
//                    Uint8 c = (argIndex == 0) ? (Uint8)arg1 : (argIndex == 1) ? (Uint8)arg2 : (Uint8)arg3;
//                    UARTa_SendByte(c);
//                    argIndex++;
//                    break;
//                }
//                default:
//                    break;
//            }
//        } else {
//            UARTa_SendByte(ch);  // ������ͨ�ַ�
//        }
//    }
//}
//
