#include "spi_init.h"

void SPI_ini (void)
	
{
	//--------------------------------------------------------------------------------------------------------------
	// настройка выводов МК для светодиодов через альтернативную функцию
	
	GPIO_InitTypeDef GPIO_Init_SPI;  // структура настройки порта подключения светодиода
	SPI_InitTypeDef SPI_init_user;
		
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);			// включение тактирования порта светодиодов
		
	GPIO_Init_SPI.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_5 | GPIO_Pin_7;	// подключение выводов порта МК, на которых расположены светодиоды
	GPIO_Init_SPI.GPIO_Mode = GPIO_Mode_AF;	// выбор режима работы порта как вывод
	GPIO_Init_SPI.GPIO_Speed = GPIO_Low_Speed;	// скорость работы порта
	GPIO_Init_SPI.GPIO_OType = GPIO_OType_PP;	// Включен режим работы "push-pull" ("двухтактный выход", его чаще всего и используют)
	GPIO_Init_SPI.GPIO_PuPd = GPIO_PuPd_NOPULL;	// без подключения подтягивающего и стягивающего резисторов
	
	GPIO_Init(GPIOA, &GPIO_Init_SPI); // Инициализация структуры порта светодиодов
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	
	//---------------------------------------------------------------------------------------------------------------
	// настройка портов МК для CS
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);			// включение тактирования порта светодиодов
		
	GPIO_Init_SPI.GPIO_Pin = GPIO_Pin_3;	// подключение выводов порта МК, на которых расположены светодиоды
	GPIO_Init_SPI.GPIO_Mode = GPIO_Mode_OUT;	// выбор режима работы порта как вывод
	GPIO_Init_SPI.GPIO_Speed = GPIO_Low_Speed;	// скорость работы порта
	GPIO_Init_SPI.GPIO_OType = GPIO_OType_PP;	// Включен режим работы "push-pull" ("двухтактный выход", его чаще всего и используют)
	GPIO_Init_SPI.GPIO_PuPd = GPIO_PuPd_NOPULL;	// без подключения подтягивающего и стягивающего резисторов
	
	GPIO_Init(GPIOE, &GPIO_Init_SPI); // Инициализация структуры порта светодиодов
	
	CS_OFF;
	
	//--------------------------------------------------------------------------------------------------------------
	// настройка SPI
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); // тактирование для SPI
	
	SPI_init_user.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_init_user.SPI_Mode = SPI_Mode_Master;
	SPI_init_user.SPI_DataSize = SPI_DataSize_8b;
	SPI_init_user.SPI_CPOL = SPI_CPOL_High;
	SPI_init_user.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_init_user.SPI_NSS = SPI_NSS_Soft;
	SPI_init_user.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	SPI_init_user.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_init_user.SPI_CRCPolynomial = 7;
	
	SPI_Init(SPI1, &SPI_init_user); // Инициализация структуры SPI
	
	SPI_Cmd(SPI1, ENABLE);
		
}


