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
            
#include "main.h"

/* Variables ----------------------------------------------------------------*/

uint8_t SPIData = 0;
char str[32] = "DMA transfer!\r\n";

/* Functions -----------------------------------------------------------------*/



int main (void)
{	
	RCC_ClocksTypeDef RCC_Clocks1;	
	RCC_GetClocksFreq(&RCC_Clocks1);
	
	LED_ini ();
	
	USART_init();
	
	// SPI_ini ();
	
	// SPI_LED_control(SPIData);	
	
	DMA_USART_ini();
	
	DMA_Cmd(DMA1_Stream6, ENABLE);
	while (1)
	{
	 
	}			
}
	
						

		
				

