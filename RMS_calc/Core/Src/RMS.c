/*
 * RMS.c
 *
 *  Created on: Apr 4, 2024
 *      Author: Professional
 */

#include "RMS.h"

// Расчет действующего значения сигнала
// Алгоритм частично описан в статье https://elibrary.ru/download/elibrary_54475580_91851937.pdf
float TrueRMS(float x_curr) {
	static float x_prev = 0;			// Предыдущее мгновенное значение входного сигнала
	static float y_prev = 0.001;		// Предыдущее значение выходного сигнала. В начальный момент взято равное 0.001, для начала расчета
	x_curr = x_curr * x_curr / y_prev;	//Делим на предыдущее, потому что текущее не знаем
	float y_curr = B0 * x_curr + B1 * x_prev - A1 * y_prev;		// Расчет текущего действущего значения сигнала
	// Запоминаем текущие значения входного сигнала и рассчитанного действующего значения
	x_prev = x_curr;
	y_prev = y_curr;

	return y_curr;

}
