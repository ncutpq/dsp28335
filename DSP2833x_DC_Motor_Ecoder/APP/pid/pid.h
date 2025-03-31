/*
 * pid.h
 *
 *  Created on: 2025Äê2ÔÂ28ÈÕ
 *      Author: Xianhao
 */

#ifndef APP_PID_PID_H_
#define APP_PID_PID_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

    typedef struct pid_calibration {
        /*
         * struct PID_Calibration
         */
        float kp; // Proportional gain
        float ki; // Integral gain
        float kd; // Derivative gain
    } PID_Calibration;


    typedef struct pid_state {
        /*
         * struct PID_State
         */
        float actual;           // The actual reading as measured
        float target;           // The desired reading
        float time_delta;       // Time since last sample/calculation - should be set when updating state
                                 // The previously calculated error between actual and target (zero initially)
        float previous_error;
        float integral;         // Sum of integral error over time
        float output;           // the modified output value calculated by the algorithm, to compensate for error
    } PID_State;


    /*
     * PID Controller Algorithm implementation
     */
    PID_State pid_iterate(PID_Calibration calibration, PID_State state);



#endif /* APP_PID_PID_H_ */
