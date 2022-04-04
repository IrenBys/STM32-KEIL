/**
  ******************************************************************************
  * @file    DMA_init.c
  * @author  Irina Bystrova
  * @brief   This file provides functions to manage the following 
  *          functionalities:           
  *           + Initialize DMA1 for USART
	*           + Initialize DMA1 for USART
	*           + Set DMA1 interrupt handler to the transmition mode
	*           + Set DMA2 interrupt handler to the transmition mode
	*           + Set DMA2 interrupt handler to the receive mode
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "DMA_init.h"

/* Variables -----------------------------------------------------------------*/

char str[32] = "DMA transfer!\r\n";		//USART transmition data buffer
uint8_t spi_rx[7];          					//SPI receive data buffer
uint8_t spi_tx[7];          					//SPI transmition data buffer
uint8_t SPI_is_working = 0; 					//SPI working flag

/* Functions -----------------------------------------------------------------*/

/**
  * @brief  Initializes DMA1 module for USART
  * @param  None
  * @retval None
  */
void DMA_USART_ini (void)
{
	/* DMA1 structure */	
	DMA_InitTypeDef DMA_USART_init_struct;
	
	/* DMA1 clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
	
	/* Sets of DMA structure */
	DMA_USART_init_struct.DMA_Channel             = DMA_Channel_4;
	DMA_USART_init_struct.DMA_PeripheralBaseAddr 	= (uint32_t) &(USART2->DR);    //The peripheral base address is USART Data Register
	DMA_USART_init_struct.DMA_Memory0BaseAddr 		= (uint32_t) str;              //The memory 0 base address is str from main.c
	DMA_USART_init_struct.DMA_DIR 								= DMA_DIR_MemoryToPeripheral;  //The data will be transferred from memory to peripheral
	DMA_USART_init_struct.DMA_BufferSize 					= DMA_buf_size;
	DMA_USART_init_struct.DMA_PeripheralInc 			= DMA_PeripheralInc_Disable;   //The Peripheral address register shouldn't be incremented
	DMA_USART_init_struct.DMA_MemoryInc 					= DMA_MemoryInc_Enable;        //The memory address register should be incremented
	DMA_USART_init_struct.DMA_PeripheralDataSize 	= DMA_PeripheralDataSize_Byte; //The Peripheral data width is one byte (8 bit)
	DMA_USART_init_struct.DMA_MemoryDataSize 			= DMA_MemoryDataSize_Byte;     //The Memory data width is one byte (8 bit)
	DMA_USART_init_struct.DMA_Mode 								= DMA_Mode_Normal; 
	DMA_USART_init_struct.DMA_Priority 						= DMA_Priority_Medium;
	DMA_USART_init_struct.DMA_FIFOMode 						= DMA_FIFOMode_Disable;
	DMA_USART_init_struct.DMA_FIFOThreshold 			=	DMA_FIFOThreshold_1QuarterFull;
	DMA_USART_init_struct.DMA_MemoryBurst 				= DMA_MemoryBurst_Single;
	DMA_USART_init_struct.DMA_PeripheralBurst 		= DMA_PeripheralBurst_Single;
	
	/* Initialization and Configuration functions */
	DMA_Init(DMA1_Stream6, &DMA_USART_init_struct);
	
	/* DMA transfers management functions */
	USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);  
	
	/*Enable External Interrupt */
	NVIC_EnableIRQ(DMA1_Stream6_IRQn); 
	
	/* DMA configurarions: stream6, TC - transmission complete */
	DMA_ITConfig(DMA1_Stream6, DMA_IT_TC, ENABLE);	
}

/**
  * @brief  Initializes DMA2 module for SPI
  * @param  None
  * @retval None
  */
void DMA_SPI_ini(void)
{
		/* DMA2 structure */
	DMA_InitTypeDef DMA_SPI_init_struct;
	
	/* DMA2 clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);	

	/* Sets of DMA2 structure to the TX mode */
	DMA_SPI_init_struct.DMA_Channel             = DMA_Channel_3;
	DMA_SPI_init_struct.DMA_PeripheralBaseAddr 	= (uint32_t) &(SPI1->DR);      //The peripheral base address is USART Data Register
	DMA_SPI_init_struct.DMA_Memory0BaseAddr 		= (uint32_t) spi_tx;              //The memory 0 base address is str from main.c
	DMA_SPI_init_struct.DMA_DIR 								= DMA_DIR_MemoryToPeripheral;  //The data will be transferred from memory to peripheral
	DMA_SPI_init_struct.DMA_BufferSize 					= 2;
	DMA_SPI_init_struct.DMA_PeripheralInc 			= DMA_PeripheralInc_Disable;   //The Peripheral address register shouldn't be incremented
	DMA_SPI_init_struct.DMA_MemoryInc 					= DMA_MemoryInc_Enable;        //The memory address register should be incremented
	DMA_SPI_init_struct.DMA_PeripheralDataSize 	= DMA_PeripheralDataSize_Byte; //The Peripheral data width is one byte (8 bit)
	DMA_SPI_init_struct.DMA_MemoryDataSize 			= DMA_MemoryDataSize_Byte;     //The Memory data width is one byte (8 bit)
	DMA_SPI_init_struct.DMA_Mode 								= DMA_Mode_Normal; 
	DMA_SPI_init_struct.DMA_Priority 						= DMA_Priority_Medium;
	DMA_SPI_init_struct.DMA_FIFOMode 						= DMA_FIFOMode_Disable;
	DMA_SPI_init_struct.DMA_FIFOThreshold 			=	DMA_FIFOThreshold_1QuarterFull;
	DMA_SPI_init_struct.DMA_MemoryBurst 				= DMA_MemoryBurst_Single;
	DMA_SPI_init_struct.DMA_PeripheralBurst 		= DMA_PeripheralBurst_Single;
	
	/* Initialization and Configuration functions to the TX mode */
	DMA_Init(DMA2_Stream3, &DMA_SPI_init_struct);
	
	/* DMA transfers management functions to the TX mode*/
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);
	
	/*Enable External Interrupt */
	NVIC_EnableIRQ(DMA2_Stream3_IRQn);
	
	/* DMA configurarions: stream3, TC - transmission complete */
	DMA_ITConfig(DMA2_Stream3, DMA_IT_TC, ENABLE);	
	
		/* Sets of DMA2 structure to the RX mode */
	DMA_SPI_init_struct.DMA_Channel             = DMA_Channel_3;
	DMA_SPI_init_struct.DMA_PeripheralBaseAddr 	= (uint32_t) &(SPI1->DR);      //The peripheral base address is USART Data Register
	DMA_SPI_init_struct.DMA_Memory0BaseAddr 		= (uint32_t) spi_rx;              //The memory 0 base address is str from main.c
	DMA_SPI_init_struct.DMA_DIR 								= DMA_DIR_PeripheralToMemory;  //The data will be transferred from memory to peripheral
	DMA_SPI_init_struct.DMA_BufferSize 					= 2;
	DMA_SPI_init_struct.DMA_PeripheralInc 			= DMA_PeripheralInc_Disable;   //The Peripheral address register shouldn't be incremented
	DMA_SPI_init_struct.DMA_MemoryInc 					= DMA_MemoryInc_Enable;        //The memory address register should be incremented
	DMA_SPI_init_struct.DMA_PeripheralDataSize 	= DMA_PeripheralDataSize_Byte; //The Peripheral data width is one byte (8 bit)
	DMA_SPI_init_struct.DMA_MemoryDataSize 			= DMA_MemoryDataSize_Byte;     //The Memory data width is one byte (8 bit)
	DMA_SPI_init_struct.DMA_Mode 								= DMA_Mode_Normal; 
	DMA_SPI_init_struct.DMA_Priority 						= DMA_Priority_Medium;
	DMA_SPI_init_struct.DMA_FIFOMode 						= DMA_FIFOMode_Disable;
	DMA_SPI_init_struct.DMA_FIFOThreshold 			=	DMA_FIFOThreshold_1QuarterFull;
	DMA_SPI_init_struct.DMA_MemoryBurst 				= DMA_MemoryBurst_Single;
	DMA_SPI_init_struct.DMA_PeripheralBurst 		= DMA_PeripheralBurst_Single;
	
	/* Initialization and Configuration functions to the RX mode */
	DMA_Init(DMA2_Stream0, &DMA_SPI_init_struct);
	
	/* DMA transfers management functions to the RX mode*/
	SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Rx, ENABLE);
	
	/*Enable External Interrupt */
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
	
	/* DMA configurarions: stream0, TC - transmission complete */
	DMA_ITConfig(DMA2_Stream0, DMA_IT_TC, ENABLE);	
}


/**
  * @brief  Initializes DMA1 interrupt handler USART
  * @param  None
  * @retval None
  */
void DMA1_Stream6_IRQHandler (void)
{
	/* if interrupt by DMA1_Stream6 */
	if (DMA_GetITStatus(DMA1_Stream6, DMA_IT_TCIF6) == SET)
	{
		/* Clear IT flag */
		DMA_ClearITPendingBit(DMA1_Stream6, DMA_IT_TCIF6);
		/* Enable transmit data function */
		DMA_Cmd(DMA1_Stream6, ENABLE);
	}
}
/**
  * @brief  Initializes DMA2 start transmition
	* @param  data_size: tne number of TX and RX data size
  * @retval None
  */
void TX_DMA_SPI(uint8_t data_size)
{
	/* tne number of TX data size */
	DMA_SetCurrDataCounter(DMA2_Stream0, data_size);
	/* tne number of RX data size */
	DMA_SetCurrDataCounter(DMA2_Stream3, data_size);
	
	/* SPI working flag */
	SPI_is_working = 1;
	
	CS_ON;
	
	/* Enable transmit data function */
	DMA_Cmd(DMA2_Stream0, ENABLE);
	/* Enable receive data function */
	DMA_Cmd(DMA2_Stream3, ENABLE);
	
}
/**
  * @brief  Wait the end of tranmition
  * @param  None
  * @retval None
  */
void SPIwait(void)
{
	while(SPI_is_working) {}
}	

/**
  * @brief  Initializes DMA2 receiving
	* @param  Adr: tne number of byte from buffer
  * @retval None
  */
uint8_t GetSPI_Rx(uint8_t Adr)
{
	return spi_rx[Adr];
}


/**
  * @brief  Initializes DMA2 transmition
	* @param  Adr: tne number of byte from a buffer
	* @param  Data: transmited data
  * @retval None
  */
void SetSPI_Tx(uint8_t Adr, uint8_t Data)
{
	if(Adr < 7)
	{
		spi_tx[Adr] = Data;
	}
}

/**
  * @brief  Check DMA SPI functionality via getting accelerometer ID
	* @param  None
	* @param  None
  * @retval None
  */
void Check_DMA_SPI(void)
{
	/* Read ID request */
	SetSPI_Tx(0, 0x8F);
	/* Read ID request */
	SetSPI_Tx(1, 0x00);
	TX_DMA_SPI(2);
	SPIwait();
	
	if(GetSPI_Rx(1) == 0x3f)
	{
		LED_RED_ON;
	} 
}	

/**
  * @brief  Initializes DMA2 RX mode interrupt handler SPI 
  * @param  None
  * @retval None
  */
void DMA2_Stream0_IRQHandler(void)
{
	if(DMA_GetITStatus(DMA2_Stream0, DMA_IT_TCIF0) == SET)
	{
		/* Clear IT flag */
		DMA_ClearITPendingBit(DMA2_Stream0, DMA_IT_TCIF0);
		
		/* Chip select mode OFF */
		CS_OFF;
		
		/* SPI working flag */
		SPI_is_working = 0;
	} 
}
/**
  * @brief  Initializes DMA2 TX mode interrupt handler SPI 
  * @param  None
  * @retval None
  */
void DMA2_Stream3_IRQHandler(void)
{
		if(DMA_GetITStatus(DMA2_Stream3, DMA_IT_TCIF3) == SET)
	{
		/* Clear IT flag */
		DMA_ClearITPendingBit(DMA2_Stream3, DMA_IT_TCIF3);
	} 
}

