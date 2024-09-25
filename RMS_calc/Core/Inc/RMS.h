/*
 * RMS.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Professional
 */

#ifndef INC_RMS_H_
#define INC_RMS_H_

//Коэффициенты разностного уравнения фильтра для расчета TrueRMS
#define B0 0.8326e-3f
#define B1 0.8326e-3f
#define A1 -0.9983f

float TrueRMS(float x_curr);

#endif /* INC_RMS_H_ */
