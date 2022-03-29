#include "usart_init.h"
#include "stm32f4xx.h"                  // Device header
#include "main.h"
#include "init.h"
#include "timer.h"
//------------------------------------------------------------------------------------------------------
// настройка выводов МК для передачи по USART
void USART2_init(void)
{
	GPIO_InitTypeDef GPIO_struct_USART;  											//структура настройки порта подключения 
	USART_InitTypeDef USART_struct;														//структура настройки USART 
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);			//включение тактирования порта 
			
	GPIO_struct_USART.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;			//подключение выводов порта МК, на которых расположены RX/TX
	GPIO_struct_USART.GPIO_Mode = GPIO_Mode_AF;								//выбор режима работы порта как альтернативная функция
	GPIO_struct_USART.GPIO_Speed = GPIO_Low_Speed;						//скорость работы порта
	GPIO_struct_USART.GPIO_OType = GPIO_OType_PP;							//Включен режим работы "push-pull" ("двухтактный выход", его чаще всего и используют)
	GPIO_struct_USART.GPIO_PuPd = GPIO_PuPd_UP;								//подтягивание вверх для надежности
	
	GPIO_Init(GPIOA, &GPIO_struct_USART); 										//Инициализация структуры порта 
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //Подключение пина RX
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2); //Подключение пина TX
//------------------------------------------------------------------------------------------------------
	// настройка модуля USART
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);		//включение тактирования USART
	
	USART_struct.USART_BaudRate 					  = 9600; 											//скорость передачи данных
	USART_struct.USART_WordLength 				  = USART_WordLength_8b; 			//длина слова
	USART_struct.USART_StopBits 					  = USART_StopBits_1; 					//объем стоп-бита
	USART_struct.USART_Parity 						  = USART_Parity_No; 							//включение/выключение проверки чётности
	USART_struct.USART_Mode 							  = USART_Mode_Rx | USART_Mode_Tx;  //режим приёма/передачи
	USART_struct.USART_HardwareFlowControl  = USART_HardwareFlowControl_None; //аппаратный режим управления потоком
	
	USART_Init(USART2, &USART_struct);
//----------------------------------------------------------------------------------------------------
// включение USART
	USART_Cmd(USART2, ENABLE);
//-----------------------------------------------------------------------------------------------------
// включение прерываний 
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); 						//прерывание на приём
	NVIC_EnableIRQ(USART2_IRQn); 															//глобальные прерывания
	
}

