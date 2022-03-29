#ifndef MAIN_H
#define MAIN_H

#include "init.h"
#include "stm32f4xx.h" 
#include "timer.h"

extern char str[32];

#define LED_GREEN_ON GPIO_SetBits(GPIOD, GPIO_Pin_12)
#define LED_GREEN_OFF GPIO_ResetBits(GPIOD, GPIO_Pin_12)

#define LED_ORANGE_ON GPIO_SetBits(GPIOD, GPIO_Pin_13)
#define LED_ORANGE_OFF GPIO_ResetBits(GPIOD, GPIO_Pin_13)

#define LED_RED_ON GPIO_SetBits(GPIOD, GPIO_Pin_14)
#define LED_RED_OFF GPIO_ResetBits(GPIOD, GPIO_Pin_14)

#define LED_BLUE_ON GPIO_SetBits(GPIOD, GPIO_Pin_15)
#define LED_BLUE_OFF GPIO_ResetBits(GPIOD, GPIO_Pin_15)

#define DELAY 200

#endif
