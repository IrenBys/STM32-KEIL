/**
  ******************************************************************************
  * @file    usart_init.c
  * @author  Irina Bystrova
  * @brief   This file provides functions to manage the following 
  *          functionalities:           
  *           + Initialize SPI module
	*						+ Set LED ports to working with SPI module
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "spi_init.h"

/* Functions -----------------------------------------------------------------*/

/**
  * @brief  Initializes SPI module
  * @param  None
  * @retval None
  */

void SPI_ini (void)	
{
	/* LED ports structure */
	GPIO_InitTypeDef GPIO_Init_SPI;

  /* SPI ports structure */	
	SPI_InitTypeDef SPI_init_user;
	
	/* Enable A and E ports clock of AHB bus */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);	
	
	/* Enable SPI clock of APB bus */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	
	/* Sets of LED	ports structure */
	GPIO_Init_SPI.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_5 | GPIO_Pin_7;
	GPIO_Init_SPI.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_Init_SPI.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init_SPI.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_SPI.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	/* Initialization LED	ports structure */	
	GPIO_Init(GPIOA, &GPIO_Init_SPI);
	
	/* Configuration LED ports as alternative function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);

	/* Sets of the LED	port structure for Chip Select mode */	
	GPIO_Init_SPI.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init_SPI.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_SPI.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init_SPI.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_SPI.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	/* Initialization LED	port structure for Chip Select mode */
	GPIO_Init(GPIOE, &GPIO_Init_SPI); // Инициализация структуры порта светодиодов
	
	/* Chip Select mode OFF*/
	CS_OFF;
	
	/* Sets of SPI ports structure */
	SPI_init_user.SPI_Direction         = SPI_Direction_2Lines_FullDuplex;
	SPI_init_user.SPI_Mode              = SPI_Mode_Master;
	SPI_init_user.SPI_DataSize          = SPI_DataSize_8b;
	SPI_init_user.SPI_CPOL              = SPI_CPOL_High;
	SPI_init_user.SPI_CPHA              = SPI_CPHA_2Edge;
	SPI_init_user.SPI_NSS               = SPI_NSS_Soft;
	SPI_init_user.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	SPI_init_user.SPI_FirstBit          = SPI_FirstBit_MSB;
	SPI_init_user.SPI_CRCPolynomial     = 7;
	
	/* Initialization SPI ports structure */
	SPI_Init(SPI1, &SPI_init_user);
	
	/* Enables SPI peripheral */
	SPI_Cmd(SPI1, ENABLE);		
}


