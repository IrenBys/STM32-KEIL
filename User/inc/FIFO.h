/**
  ******************************************************************************
  * @file    FIFO.h
  * @author  Irina Bystrova
  * @brief   This file contains all the functions prototypes for the FIFO.
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef _FIFO_H_
#define _FIFO_H_

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "stdint.h"

/* Exported types ------------------------------------------------------------*/

/** 
  * @brief  FIFO buffer structure  uint8_t
  */
typedef struct _FIFO_s
{ 
    uint8_t Head;
    uint8_t Tail;
    uint8_t Max;
    char *Data;
    
}FIFO_s, *pFIFO_s;

/* Exported functions --------------------------------------------------------*/

pFIFO_s FifoCreateFIFO(uint8_t Max);
void FifoDeleteFIFO(pFIFO_s Point);
uint8_t FifoCreatePairFIFO(pFIFO_s *inPoint, uint8_t inMax, pFIFO_s *outPoint, uint8_t outMax);
void FifoDeletePairFIFO(pFIFO_s *inPoint, pFIFO_s *outPoint);
uint8_t FifoSetByteToFIFO(pFIFO_s Point, char Data);
uint8_t FifoSetNBytesToFIFO(pFIFO_s Point, char *Data, uint8_t Len);
uint8_t FifoGetByteFromFIFO(pFIFO_s Point, char *Data);
uint8_t FifoGetNBytesFromFIFO(pFIFO_s Point, char *Data, uint8_t Len);
uint8_t FifoGetNBytesFromFIFONoChangePoints(pFIFO_s Point, char *Data, uint8_t Len);
uint8_t FifoSetByteNToFIFONoChangePoints(pFIFO_s Point, char Data, uint8_t N);
uint8_t FifoKeyhitFIFO(pFIFO_s Point);
uint8_t FifoPointPlus(uint8_t p, uint8_t max);
uint8_t FifoFIFO2FIFO(pFIFO_s inPoint, pFIFO_s outPoint);

#endif /*_FIFO_H_ */
