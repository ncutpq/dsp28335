/*
 * main.c
 *
 *  Created on: 2018-3-21
 *      Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "leds.h"
#include "beep.h"
#include "relay.h"
#include "key.h"
#include "epwm.h"
#include "dc_motor.h"
#include "time.h"
#include "uart.h"
#include "eqep.h"
#include "epwm.h"
#include "pid.h"
#include "smg.h"

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
float E_Speed = 0.0; // 编码器位置值
char key = 0;
float speed = 0.0;
PID_Calibration calibration;
PID_State state;
void PID_Init(void);


void main()
{


    InitSysCtrl();//系统时钟初始化，默认已开启F28335所有外设时钟
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

	LED_Init();
	KEY_Init();
	SMG_Init();
	DC_Motor_Init();
	EPWM1_Init(1200);
    TIM0_Init(150,200000); //150MHz下定时 200ms
    EQEP2_Init();
    PID_Init();

    UARTa_Init(4800);

	while(1)
	{
        key = KEY_Scan(0);
        switch(key)
        {
            case KEY1_PRESS: speed += 100; if(speed> 1200) speed = 1200;LED2_TOGGLE;break;
            case KEY2_PRESS: speed -= 100; if(speed< -1200) speed = -1200;LED3_TOGGLE;break;
            case KEY3_PRESS: calibration.kp += 0.2; LED4_TOGGLE;break;
            case KEY4_PRESS: calibration.kp -= 0.2; LED4_TOGGLE;break;
            case KEY5_PRESS: calibration.ki += 0.1;LED5_TOGGLE;break;
            case KEY6_PRESS: calibration.ki -= 0.1;LED5_TOGGLE;break;
            case KEY7_PRESS: calibration.kd += 0.1;LED6_TOGGLE;break;
            case KEY8_PRESS: calibration.kd -= 0.1;LED6_TOGGLE;break;
            case KEY9_PRESS: Motor_SetSpeed(0); LED7_TOGGLE;break;
        }
        state.target = speed;
        E_Speed = get_encoder_val();
        state.actual = E_Speed;
        state = pid_iterate(calibration,state);
        Motor_SetSpeed(state.output);
//        Motor_SetSpeed(10);

//        DELAY_US(10); // 100ms
//        SMG_DisplayInt(state.actual);
    }
}

void PID_Init(void)
{
    // configure the calibration and state structs
    // dummy gain values
    calibration.kp = 0.8;
    calibration.ki = 0.0;
    calibration.kd = 0.0;
    // an initial blank starting state
    state.actual = 0.0;
    state.target = 0.0;
    state.time_delta =1.0; // assume an arbitrary time interval of 1.0
    state.previous_error = 0.0;
    state.integral = 0.0;
}

