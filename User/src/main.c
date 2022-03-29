#include "stm32f4xx.h"                  // Device header
#include "main.h"
#include "init.h"
#include "timer.h"
#include "usart_init.h"
#include "DMA.h"

char str[32] = "DMA transfer!\r\n";

int main (void)
{	
	RCC_ClocksTypeDef RCC_Clocks1;
	
	RCC_GetClocksFreq(&RCC_Clocks1);
	
	USART2_init();
	
	DMA_USART_ini();
	
	DMA_Cmd(DMA1_Stream6, ENABLE);
	while (1)
	{
	 
	}			
}
	
						

		
				

