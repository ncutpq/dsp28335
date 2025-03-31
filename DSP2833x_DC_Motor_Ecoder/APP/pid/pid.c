/*
 * pid.c
 *
 *  Created on: 2025年2月28日
 *      Author: Xianhao
 */

#include "pid.h"

#define MAX_OUTPUT 1200.0
#define MIN_OUTPUT 0.0

PID_State pid_iterate(PID_Calibration calibration, PID_State state) {
  // calculate difference between desired and actual values (the error)
  float error = state.target - state .actual;

  state.integral += (error * state.time_delta);
  //积分限幅
  if(state.integral > 1000) state.integral = 1000;

  // calculate derivative
  float derivative = (error - state.previous_error) / state.time_delta;
  // calculate output value according to algorithm
  state.output = ((calibration.kp * error) + (calibration.ki * state.integral) +
                  (calibration.kd * derivative));

  if(state.output > MAX_OUTPUT) state.output = MAX_OUTPUT;
  else if(state.output < MIN_OUTPUT) state.output = MIN_OUTPUT;

  // update state.previous_error to the error value calculated on this iteration
  state.previous_error = error;
  // return the state struct reflecting the calculations
  return state;
}


