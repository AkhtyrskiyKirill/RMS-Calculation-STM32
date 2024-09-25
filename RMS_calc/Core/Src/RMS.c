/*
 * RMS.c
 *
 *  Created on: Apr 4, 2024
 *      Author: Professional
 */

#include "RMS.h"

float TrueRMS(float x_curr) {
	static float x_prev = 0;
	static float y_prev = 0.001;
	x_curr = x_curr * x_curr / y_prev;	//Делим на предыдущее, потому что текущее не знаем
	float y_curr = B0 * x_curr + B1 * x_prev - A1 * y_prev;
	x_prev = x_curr;
	y_prev = y_curr;

	return y_curr;

}
