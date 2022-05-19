/**
  ******************************************************************************
  * @file    FIFO.c
  * @author  Irina Bystrova
  * @brief   This file provides functions to manage the following
  *          functionalities:
  *           + Create FIFO buffer
  *           + Delete FIFO buffer
  *           + Create a pair of FIFO buffers (input/output)
  *           + Delete a pair of FIFO buffers (input/output)
  *           + Write a byte in the FIFO
  *           + Write N bytes in the FIFO
  *           + Read a byte in the FIFO
  *           + Read N byte in the FIFO
  *           + Return the number of unprocessed bytes in the FIFO
  *           + Increment the pointer based onthe lenght of FIFO
  *           + Write all unprocessed bytes from FIFO to FIFO
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "FIFO.h"

/* Functions -----------------------------------------------------------------*/

/**
    * @brief  Creates a FIFO buffer
    * @param  Max: a size of the FIFO buffer will be create
    * @retval pointer to a FIFO buffer structure
    */
pFIFO_s FifoCreateFIFO(uint8_t Max)
{
    pFIFO_s Point;
    Max++;
    if((Point = (pFIFO_s)(malloc(sizeof(FIFO_s)))) == NULL)
    {
        return NULL;
    }
    if((Point->Data = (char *)(malloc(Max))) == NULL)
    {
        free(Point);
        return NULL;
    }
    Point->Head = 1;
    Point->Tail = 0;
    Point->Max  = Max;
    return Point;
}

/**
    * @brief  Deletes a FIFO buffer
    * @param  Point: pointer to a FIFO buffer structure will be delete
    * @retval None
    */
void FifoDeleteFIFO(pFIFO_s Point)
{
    if(Point != NULL)
    {
        free(Point->Data);
        free(Point);
    }
}
/**
    * @brief  Creates a pair FIFO buffer
    * @param  inPoint: pointer to a input FIFO buffer structure will be create
    * @param  inMax: a size of the input FIFO buffer will be create
    * @param  outPoint: pointer to a output FIFO buffer structure will be create
    * @param  outMax: a size of the output FIFO buffer will be create
    * @retval uint8_t
    */
uint8_t FifoCreatePairFIFO(pFIFO_s *inPoint, uint8_t inMax, pFIFO_s *outPoint, uint8_t outMax)
{
    FifoDeletePairFIFO(inPoint, outPoint);

    if((*inPoint = FifoCreateFIFO(inMax)) == NULL)
    {
        return 0;
    }

    if((*outPoint = FifoCreateFIFO(outMax)) == NULL)
    {
        FifoDeleteFIFO(*inPoint);
        return 0;
    }
    return 1;
}

/**
    * @brief  Deletes a pair FIFO buffer
    * @param  inPoint: pointer to a input FIFO buffer structure will be delete
    * @param  outPoint: pointer to a output FIFO buffer structure will be delete
    * @retval None
    */
void FifoDeletePairFIFO(pFIFO_s *inPoint, pFIFO_s *outPoint)
{
    if(*inPoint != NULL)
    {
        FifoDeleteFIFO(*inPoint);
    }

    if(*outPoint != NULL)
    {
        FifoDeleteFIFO(*outPoint);
    }
}

/**
    * @brief  Writes a byte in the FIFO
    * @param  Point: pointer to a FIFO buffer structure in that a byte will be write
    * @param  Data: a byte that will be write
    * @retval uint8_t
    */
uint8_t FifoSetByteToFIFO(pFIFO_s Point, char Data)
{
    if(Point->Head == Point->Tail)
    {
        return 0;
    }

    Point->Data[Point->Head] = Data;
    Point->Head = FifoPointPlus((Point->Head), Point->Max);
    return 1;
}

/**
    * @brief  Writes N byte in the FIFO
    * @param  Point: pointer to a FIFO buffer structure in that N byte will be write
    * @param  Data: a poiner to bytes that will be write
    * @param  Len: the lenght of bytes
    * @retval The lenght of the written bytes
    */
uint8_t FifoSetNBytesToFIFO(pFIFO_s Point, char *Data, uint8_t Len)
{
    uint8_t i;

    for(i = 0; i < Len; i++)
    {
        if(FifoSetByteToFIFO(Point, Data[i]) == 0)
        {
            break;
        }
    }
    return i;
}

/**
    * @brief  Reads a byte in the FIFO
    * @param  Point: pointer to a FIFO buffer structure in that a byte will be read
    * @param  Data: a byte that will be read
    * @retval uint8_t
    */
uint8_t FifoGetByteFromFIFO(pFIFO_s Point, char *Data)
{
    if(!FifoKeyhitFIFO(Point))
    {
        return 0;
    }

    Point->Tail = FifoPointPlus(Point->Tail, Point->Max);
    *Data = Point->Data[Point->Tail];
    return 1;
}

/**
    * @brief  Reads N byte in the FIFO
    * @param  Point: pointer to a FIFO buffer structure in that N byte will be read
    * @param  Data: a poiner to bytes that will be read
    * @param  Len: the lenght of bytes
    * @retval The lenght of the read bytes
    */
uint8_t FifoGetNBytesFromFIFO(pFIFO_s Point, char *Data, uint8_t Len)
{ 
    uint8_t i;

    for(i = 0; i < Len; i++)
    {
        if(FifoGetByteFromFIFO(Point, &Data[i]) == 0)
        { 
            break;
        }
    }
    return i;
}
/**
    * @brief  Returns the number of unprocessed bytes in the FIFO
    * @param  Point: pointer to a FIFO buffer structure
    * @retval The number of unprocessed bytes in the FIFO
    */
uint8_t FifoKeyhitFIFO(pFIFO_s Point)
{
    if(Point->Head > Point->Tail)
    {
        return (Point->Head - Point->Tail - 1);
    }
    else
    {
        return (Point->Max - (Point->Tail - Point->Head) - 1);
    }
}

/**
    * @brief  Increments the pointer based on the lenght of FIFO
    * @param  p: increment
    * @param  max: the max size
    * @retval The number increments
    */
uint8_t FifoPointPlus(uint8_t p, uint8_t max)
{
    if(++p >= max)
    {
        p = 0;
    }
    return p;
}

/**
    * @brief  Writes all unprocessed bytes from FIFO to FIFO
    * @param  inPoint: pointer to a input FIFO buffer structure will be write
    * @param  outPoint: pointer to a output FIFO buffer structure will be read
    * @retval uint8_t
    */
uint8_t FifoFIFO2FIFO(pFIFO_s inPoint, pFIFO_s outPoint)
{
    char Data;

    // while returns the number of unprocessed bytes in the FIFO
    while(FifoKeyhitFIFO(inPoint))
    {
        // overflow
        if(outPoint->Head == outPoint->Tail)
        {
            return 0;
        }

        FifoGetByteFromFIFO(inPoint, &Data);

        if(FifoSetByteToFIFO(outPoint, Data) == 0)
        {
            return 0;
        }
    }
    return 1;
}
