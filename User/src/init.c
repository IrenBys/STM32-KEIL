#include "stm32f4xx.h"                  // Device header
#include "main.h"
#include "init.h"
#include "timer.h"


void LED_ini(void)
{
	GPIO_InitTypeDef GPIO_struct_LED;  // структура настройки порта подключения светодиода
		
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);			// включение тактирования порта светодиодов
	
	SystemCoreClockUpdate();
	
	SysTick_Config(SystemCoreClock /1000);	//1ms
	
	GPIO_struct_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;	// подключение выводов порта МК, на которых расположены светодиоды
	GPIO_struct_LED.GPIO_Mode = GPIO_Mode_OUT;	// выбор режима работы порта как вывод
	GPIO_struct_LED.GPIO_Speed = GPIO_Low_Speed;	// скорость работы порта
	GPIO_struct_LED.GPIO_OType = GPIO_OType_PP;	// Включен режим работы "push-pull" ("двухтактный выход", его чаще всего и используют)
	GPIO_struct_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;	// без подключения подтягивающего и стягивающего резисторов
	
	GPIO_Init(GPIOD, &GPIO_struct_LED); // Инициализация структуры порта светодиодов
}
