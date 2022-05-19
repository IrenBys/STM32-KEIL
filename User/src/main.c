/**
  ******************************************************************************
  * @file    main.c
  * @author  Irina Bystrova
  * @brief   This file contains the main function to manage the following 
  *          functionalities:
  *           + initializes the peripheral modules: USART, DMA, SPI	
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
            
#include "main.h"

/* Functions -----------------------------------------------------------------*/

int main (void)
{	
    /* Enables clock */
    RCC_ClocksTypeDef RCC_Clocks1;	
    RCC_GetClocksFreq(&RCC_Clocks1);
    
    LED_ini();
    
    /* Uncomment the line below for USART DMA transmition enable*/
    //USART_init();	
    //DMA_USART_ini();	
    //DMA_Cmd(DMA1_Stream6, ENABLE);
    
    
    /* Uncomment the line below for SPI DMA transmition/receiving enable*/
    //SPI_ini();	
    //DMA_SPI_ini();
    //Check_DMA_SPI();	
    
    while (1)
    {
     
    }			
}
    
                        

        
                

