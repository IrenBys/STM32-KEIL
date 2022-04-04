# STM32-KEIL
Projects. STM32F4DISCOVERY.

The project is created for the STM32F407VG Discovery Kit using the Keil µVision and the STM32F4xx_StdPeriph_Driver Library.
The aim of creation of this project is to understand how to DMA (Direct Access Memory) module works in the STM32F407VG Discovery Kit.

This project consist of the following main folders:
- CMSIS Cortex-M4 Device System Source and Header Files for STM32F4xx devices;
- STM32F4xx_StdPeriph_Driver Library; 
- USER Source and Header Files.

The first two folders were taken from the official STM website https://www.st.com/

The USER folder consist of:
- The main function where the peripheral modules are called: USART, DMA, SPI;
- The initializing the peripheral module files usart_init, DMA_init, spi_init, timer, init (LEDs_ini function).

This project implements the transmission and reception of data using USART and SPI protocols by DMA.
