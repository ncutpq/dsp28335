/*
 * uart.h
 *
 *  Created on: 2025��2��25��
 *      Author: Xianhao
 */

#ifndef APP_UART_UART_H_
#define APP_UART_UART_H_


#include "DSP2833x_Device.h"     // DSP2833x ͷ�ļ�
#include "DSP2833x_Examples.h"   // DSP2833x �������ͷ�ļ�


void UARTa_Init(Uint32 baud);
void UARTa_SendByte(int a);
void UARTa_SendString(char * msg);
void printf(const char *format, Uint32 num);

#endif /* APP_UART_UART_H_ */
