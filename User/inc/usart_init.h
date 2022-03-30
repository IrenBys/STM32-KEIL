/**
  ******************************************************************************
  * @file    usart_init.h
  * @author  Irina Bystrova
  * @brief   This file contains all the functions prototypes for  
	*					 the initialization LEDs and USART modules.
  ******************************************************************************
  */
	
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef USART_INIT_H
#define USART_INIT_H

/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Exported constants --------------------------------------------------------*/

/* set USART parameters */
#define BAUD_RATE   115200
#define PARITY_BIT  USART_Parity_No
#define WORD_LENGHT USART_WordLength_8b
#define STOP_BIT		USART_StopBits_1

/* Exported functions --------------------------------------------------------*/

void USART_init(void);
void LED_ini(void);

#endif /*USART_INIT_H */
