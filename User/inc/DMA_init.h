/**
  ******************************************************************************
  * @file    DMA_init.h
  * @author  Irina Bystrova
  * @brief   This file contains all the functions prototypes DMA.
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef USART_INIT_H
#define USART_INIT_H

/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Exported constants --------------------------------------------------------*/

/* The buffer size, in data unit */
#define DMA_buf_size 15

/* Exported functions --------------------------------------------------------*/

void DMA_USART_ini(void);

#endif /* USART_INIT_H */
