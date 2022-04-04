/**
  ******************************************************************************
  * @file    spi_init.h
  * @author  Irina Bystrova
  * @brief   This file contains all the functions prototypes SPI.
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef SPI_INIT_H
#define SPI_INIT_H

/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Exported constants --------------------------------------------------------*/

#define CS_OFF GPIO_SetBits(GPIOE, GPIO_Pin_3)
#define CS_ON GPIO_ResetBits(GPIOE, GPIO_Pin_3)

/* Exported functions --------------------------------------------------------*/

void SPI_ini(void);
// void SPI_LED_control(uint8_t Data);

#endif /* SPI_INIT_H */
