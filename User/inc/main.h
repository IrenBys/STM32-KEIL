/**
  ******************************************************************************
  * @file    main.h
  * @author  Irina Bystrova
  * @brief   This file contains all includes and defines for main.c
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef MAIN_H
#define MAIN_H

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx.h"                 
#include <stdlib.h>
#include "Types.h"
#include "FIFO.h"
#include "init.h"
#include "timer.h"
#include "DMA_init.h"
#include "usart_init.h"
#include "spi_init.h"

/* Defines --------------------------------------------------------------------*/

#define DELAY 200

#endif /* MAIN_H */
