#include "stm32f4xx.h"                  // Device header
#include "main.h"
#include "init.h"
#include "timer.h"

//обработчик прерываний

void TIM2_IRQHandler(void)
{
	//проверим было ли прерывание

	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)		/* проверяем действительно ли было прерывание 
																																по пререполнению TIM_IT_Update*/
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);				/*сброс флага*/
		GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
	}
	
}

//16-битный таймер №2 должен вызывать прерывания раз в секунду

void timer_ini(void)
{
	
	//включили тактирование таймера и настроили таймер
	
	TIM_TimeBaseInitTypeDef timer_struct; 							// объявление переменной структуры для иниализации таймера
	NVIC_InitTypeDef NVIC_struct;												// объявление переменной структуры для разрешения прерываний
	
	RCC_AHB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);// тактирование таймера 2
	
	timer_struct.TIM_Prescaler = 20000-1; 							/*	Чтобы таймер выдавал прерывания каждую секунду, 
																													надо поделелить входную частоту, поступающую 
																													на модуль таймера (20 Мгц), на 20000. 
																													Тогда частота тактирования таймера 1 кГц и 
																													таймер будет считать до 1000 */
	timer_struct.TIM_CounterMode = TIM_CounterMode_Up;	/*	Режим работы таймера вверх */
	timer_struct.TIM_Period = 1000;											/*	период отсчетов 1 кГЦ = 1000 раз */
	timer_struct.TIM_ClockDivision = TIM_CKD_DIV1;			/*	специфическая функция. выбрали деление на 1 */
	timer_struct.TIM_RepetitionCounter = 0;							/*	специфическая функция. */
	
	TIM_TimeBaseInit(TIM2, &timer_struct);							/*	функция инициализации таймера*/
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);					/*	функция конфигурирования прерываний по переполнению*/
	
	//включили и настроили прерывания
	
	NVIC_struct.NVIC_IRQChannel = TIM2_IRQn;						/*	то глобальное прерывание которое нужно включить*/
	NVIC_struct.NVIC_IRQChannelPreemptionPriority = 0;	/*	приоритет прерываний*/
	NVIC_struct.NVIC_IRQChannelSubPriority = 0;					/*	нулевая группа, нулевая очередь */ 
	NVIC_struct.NVIC_IRQChannelCmd = ENABLE;						/*	включаем прерывание*/
	
	NVIC_Init(&NVIC_struct); 														/*инициализация структуры разрешения прерываний*/
	

	//далее включаем сам таймер
	
	TIM_Cmd(TIM2, ENABLE);
}
