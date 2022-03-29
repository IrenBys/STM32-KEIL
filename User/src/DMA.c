#include "stm32f4xx.h"  
#include "main.h"
#include "DMA.h"


//-------------------------------------------------------------------------
// enable DMA clock

void DMA_USART_ini (void)
{
	//DMA structure
	DMA_InitTypeDef DMA_USART_init_struct;
	
	//DMA1 clock enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
	//The channel 4 is used 
	DMA_USART_init_struct.DMA_Channel 						= DMA_Channel_4;
	//The peripheral base address is USART Data Register
	DMA_USART_init_struct.DMA_PeripheralBaseAddr 	= (uint32_t) &(USART2->DR);
	//The memory 0 base address is str from main.c
	DMA_USART_init_struct.DMA_Memory0BaseAddr 		= (uint32_t) str;
	//The data will be transferred from memory to peripheral
	DMA_USART_init_struct.DMA_DIR 								= DMA_DIR_MemoryToPeripheral;
	//The buffer size, in data unit
	DMA_USART_init_struct.DMA_BufferSize 					= 15;
	//The Peripheral address register shouldn't be incremented 
	DMA_USART_init_struct.DMA_PeripheralInc 			= DMA_PeripheralInc_Disable;
	//The memory address register should be incremented
	DMA_USART_init_struct.DMA_MemoryInc 					= DMA_MemoryInc_Enable;
	//The Peripheral data width is one byte (8 bit)
	DMA_USART_init_struct.DMA_PeripheralDataSize 	= DMA_PeripheralDataSize_Byte;
	//The Memory data width is one byte (8 bit)
	DMA_USART_init_struct.DMA_MemoryDataSize 			= DMA_MemoryDataSize_Byte;
	//The operation mode is Normal
	DMA_USART_init_struct.DMA_Mode 								= DMA_Mode_Normal;
	//The software priority is Medium
	DMA_USART_init_struct.DMA_Priority 						= DMA_Priority_Medium;
	//The FIFO mode or Direct mode won't be used
	DMA_USART_init_struct.DMA_FIFOMode 						= DMA_FIFOMode_Disable;
	DMA_USART_init_struct.DMA_FIFOThreshold 			=	DMA_FIFOThreshold_1QuarterFull;
	//the Burst transfer configuration for the memory transfers: one byte - one transaction
	DMA_USART_init_struct.DMA_MemoryBurst 				= DMA_MemoryBurst_Single;
	//the Burst transfer configuration for the peripheral transfers
	DMA_USART_init_struct.DMA_PeripheralBurst 		= DMA_PeripheralBurst_Single;
	//Initialization and Configuration functions
	DMA_Init(DMA1_Stream6, &DMA_USART_init_struct);
	//DMA transfers management functions
	USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
	//Enable External Interrupt
	NVIC_EnableIRQ(DMA1_Stream6_IRQn); 
	//DMA configurarions: stream6, TC - transmission complete
	DMA_ITConfig(DMA1_Stream6, DMA_IT_TC, ENABLE);	
}

void DMA1_Stream6_IRQHandler (void)
{
	//if interrupt by DMA1_Stream6
	if (DMA_GetITStatus(DMA1_Stream6, DMA_IT_TCIF6) == SET)
	{
		//Clear IT flag
		DMA_ClearITPendingBit(DMA1_Stream6, DMA_IT_TCIF6);
		//transmit data
		DMA_Cmd(DMA1_Stream6, ENABLE);
	}
}

