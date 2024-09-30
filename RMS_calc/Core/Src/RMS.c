/*
 * RMS.c
 *
 *  Created on: Apr 4, 2024
 *      Author: Professional
 */

#include "RMS.h"

// Initialization of RMS calculation block (Must be called once for each signal, which RMS is calculated, before start of calculation)
void RMS_Init(tRMSCalc * RMS_Var) {
	RMS_Var->MulDivPrev = 0;																			// Previous (instant^2)/RMSPrev
	RMS_Var->RMSPrev = RMS_PREV_VAL;																	// Previous RMS value of the signal
	RMS_Var->RMSVal = 0;																				// RMS value of the signal
}

// RMS Calculation step (Need several steps to reach steady state of RMS)
// Algorithm is described in an article https://elibrary.ru/download/elibrary_54475580_91851937.pdf
void RMS_Step(tRMSCalc * RMS_Var) {
	float tmp = RMS_Var->InstantVal * RMS_Var->InstantVal / RMS_Var->RMSPrev;
	RMS_Var->RMSVal = B0 * tmp + B1 * RMS_Var->MulDivPrev - A1 * RMS_Var->RMSPrev;

	RMS_Var->MulDivPrev = tmp;
	RMS_Var->RMSPrev = RMS_Var->RMSVal;

}
