# Signal RMS Calculation library

This library implements an RMS calculation algorithm which allows to calculate RMS values of input signal.  

## How to use the library

For each signal, RMS value of which you want to calculate, you need to create an instance of type tRMSCalc.  
Then you need to initialize the calculation block by using void RMS_Init(tRMSCalc * RMS_Var) function (it's input  
is pointer to corresponding tRMSCalc var; if you calculate RMS of several signals, you must initialize the  
calculation block for every signal). When you get the next instantaneous value of this signal (from ADC some  
interface, etc.), you need to use the float RMS_Step(tRMSCalc * RMS_Var, float Instant) function which takes this  
value as it's second input. The first input of this function is a pointer to corresponding tRMSCalc var.  
The function outputs the RMS value of this signal. It needs several steps to reach steady state of RMS value.

## Example

In the files you can find an example project for STM32 dev board NUCLEO-F429ZI. All the example code is in main.c  
file (main function and HAL_TIM_PeriodElapsedCallback function). The example uses timer TIM1 with 4 kHz frequency  
which simulates three signals (sine, square and sawtooth waves with 50 Hz frequency, captured with 4 kHz sampling  
frequency). The RMS values are stored to RMS_Sin_Val, RMS_Square_Val, RMS_Saw_Val variables.

## Reference to the RMS calculation algorithm

The RMS Calculation algorithm is described in the article: 
Кузнецов Д. Н., Захарченко И. А. СПОСОБ ИЗМЕРЕНИЯ TRUE RMS ПЕРЕМЕННОГО НАПРЯЖЕНИЯ С ПОМОЩЬЮ МИКРОКОНТРОЛЛЕРА //АВТОМАТИЗАЦИЯ ТЕХНОЛОГИЧЕСКИХ ОБЪЕКТОВ И ПРОЦЕССОВ. ПОИСК МОЛОДЫХ. – 2023. – С. 121-124.