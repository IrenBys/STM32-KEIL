/**
  ******************************************************************************
  * @file    main.c
  * @author  Irina Bystrova
  * @brief   This file contains the main function to manage the following 
  *          functionalities:
	*           + initializes the peripheral modules: LEDs, USART, DMA, SPI	
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx.h"                 
#include "main.h"
#include "init.h"
#include "timer.h"
#include "usart_init.h"
#include "spi_init.h"
#include "DMA.h"

/* Variables ----------------------------------------------------------------*/

uint8_t SPIData = 0;
char str[32] = "DMA transfer!\r\n";

/* Functions -----------------------------------------------------------------*/

void SPI_LED_control(uint8_t Data)
{
	/* Chip Select mode ON */
	CS_ON;  	
	
	SPI_I2S_SendData(SPI1, 0x8f);
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY)== SET) {}
	SPI_I2S_ReceiveData(SPI1);
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY)== SET) {}	
	SPI_I2S_SendData(SPI1, 0x00);
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY)== SET) {}
	SPI_I2S_ReceiveData(SPI1);
	
	/* Chip Select mode OFF*/
	CS_OFF;
		
	if (Data == 0x3b)
	{
		LED_GREEN_ON;
	}
	if (Data == 0x3f)
	{
		LED_RED_ON;
	}
}

int main (void)
{	
	RCC_ClocksTypeDef RCC_Clocks1;	
	RCC_GetClocksFreq(&RCC_Clocks1);
	
	LED_ini ();
	
	USART_init();
	
	SPI_ini ();
	
	SPI_LED_control(SPIData);	
	
	DMA_USART_ini();
	
	DMA_Cmd(DMA1_Stream6, ENABLE);
	while (1)
	{
	 
	}			
}
	
						

		
				

