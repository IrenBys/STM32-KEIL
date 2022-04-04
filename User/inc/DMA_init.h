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
void DMA_SPI_ini(void);
void TX_DMA_SPI(uint8_t data_size);
void SPIwait(void);
void SetSPI_Tx(uint8_t Adr, uint8_t Data);
uint8_t GetSPI_Rx(uint8_t Adr);
void Check_DMA_SPI(void);

#endif /* USART_INIT_H */
