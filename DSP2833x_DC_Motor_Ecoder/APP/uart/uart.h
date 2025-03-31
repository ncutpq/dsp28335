/*
 * uart.h
 *
 *  Created on: 2025年2月25日
 *      Author: Xianhao
 */

#ifndef APP_UART_UART_H_
#define APP_UART_UART_H_


#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件


void UARTa_Init(Uint32 baud);
void UARTa_SendByte(int a);
void UARTa_SendString(char * msg);
void printf(const char *format, Uint32 num);

#endif /* APP_UART_UART_H_ */
