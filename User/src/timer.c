/**
  ******************************************************************************
  * @file    timer.c
  * @author  Irina Bystrova
  * @brief   This file provides functions to manage the following 
  *          functionalities:           
  *           + Initialize interrupt timer_2 handler
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/

#include "timer.h"

/* Functions -----------------------------------------------------------------*/

/**
  * @brief  Initializes interrupt timer handler
  * @param  None
  * @retval None
  */
void TIM2_IRQHandler(void)
{
	/* check if an overflow interrupt has occured */
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
	}	
}

/**
  * @brief  Initializes timer_2 
  * @param  None
  * @retval None
  */
void timer_ini(void)
{		
	/* Timer initialize structure */
	TIM_TimeBaseInitTypeDef timer_struct;
	
  /* NVIC structure for an interrupt */	
	NVIC_InitTypeDef NVIC_struct;	
	
	/* Timer_2 clock enable */
	RCC_AHB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	/* Sets of timer initialize structure */
	timer_struct.TIM_Prescaler         = Prescaler_1sec;
	timer_struct.TIM_CounterMode       = TIM_CounterMode_Up;
	timer_struct.TIM_Period            = Period_1Hz;
	timer_struct.TIM_ClockDivision     = TIM_CKD_DIV1;
	timer_struct.TIM_RepetitionCounter = 0;
	
	/* Initialize timer initialize structure */
	TIM_TimeBaseInit(TIM2, &timer_struct);
	
	/* Configure timer overflow interrupt function */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	/* Sets of NVIC structure for an interrupt */	
	NVIC_struct.NVIC_IRQChannel                   = TIM2_IRQn;						
	NVIC_struct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_struct.NVIC_IRQChannelSubPriority        = 0; 
	NVIC_struct.NVIC_IRQChannelCmd                = ENABLE;
	
	/* Initialize NVIC structure for an interrupt */
	NVIC_Init(&NVIC_struct);	

	/* Enable timer_2 */
	TIM_Cmd(TIM2, ENABLE);
}
