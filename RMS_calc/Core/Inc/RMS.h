/*
 * RMS.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Professional
 */

#ifndef INC_RMS_H_
#define INC_RMS_H_

// Previous RMS value before algorithm start (can not be 0)
#define RMS_PREV_VAL 0.001f

//Equation coefficients to calculate RMS
#define B0 0.8326e-3f
#define B1 0.8326e-3f
#define A1 -0.9983f

// RMS calculation value (an instance needed for each signal, which RMS is calculated)
typedef struct {
	float MulDivPrev;					// Previous ((Instant^2)/RMSPrev) value
	float RMSPrev;						// Previous RMS value of the signal
} tRMSCalc;

// Initialization of RMS calculation block (Must be called once for each signal, which RMS is calculated, before start of calculation)
void RMS_Init(tRMSCalc * RMS_Var);

// RMS Calculation step (Need several steps to reach steady state of RMS)
// Algorithm is described in an article https://elibrary.ru/download/elibrary_54475580_91851937.pdf
// Returns RMS value of a signal.
float RMS_Step(tRMSCalc * RMS_Var, float Instant);

#endif /* INC_RMS_H_ */
