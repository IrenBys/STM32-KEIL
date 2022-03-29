#ifndef SPI_INIT_H
#define SPI_INIT_H

#include "stm32f4xx.h"  
#include "main.h"

#define CS_OFF GPIO_SetBits(GPIOE, GPIO_Pin_3)
#define CS_ON GPIO_ResetBits(GPIOE, GPIO_Pin_3)

void SPI_ini(void);

#endif
