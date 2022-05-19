/**
  ******************************************************************************
  * @file    init.c
  * @author  Irina Bystrova
  * @brief   This file provides functions to manage the following 
  *          functionalities:           
  *           + Initialize LEDs
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "init.h"

/* Functions -----------------------------------------------------------------*/

/**
  * @brief  Initializes LEDs
  * @param  None
  * @retval None
  */
    void LED_ini(void)
{
    GPIO_InitTypeDef GPIO_struct_LED; 
        
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);	
    
    SystemCoreClockUpdate();
    
    SysTick_Config(SystemCoreClock /1000);	//1ms
    
    GPIO_struct_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_struct_LED.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_struct_LED.GPIO_Speed = GPIO_Low_Speed;
    GPIO_struct_LED.GPIO_OType = GPIO_OType_PP;
    GPIO_struct_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
    
    GPIO_Init(GPIOD, &GPIO_struct_LED);
}
