/**
  ******************************************************************************
  * @file    timer.h
  * @author  Irina Bystrova
  * @brief   This file contains all the functions prototypes for timers.
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef TIMER_H
#define TIMER_H

/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Exported constants --------------------------------------------------------*/

/* In order for the timer to issue interrupts every second, 
 * it is necessary to divide the input frequency supplied 
 * to the timer module (20 MHz) by 20000. Then the clock 
 * frequency of the timer is 1 kHz and the timer will count 
 * up to 1000 */
#define Prescaler_1sec 20000-1
#define Period_1Hz     1000

/* Exported functions --------------------------------------------------------*/

void TIM2_IRQHandler (void);
void timer_ini (void);

#endif /* TIMER_H */
