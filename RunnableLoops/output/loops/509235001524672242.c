#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (const int vChrFilterSize, int i, const int chrDstY,
    int32_t * chrMmxFilter, const int16_t ** chrUSrcPtr, int16_t * vChrFilter)
{
  for (i = 0; i < vChrFilterSize; i++)
    {
      *(const void * *) &chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];
      chrMmxFilter[4 * i + 2] = chrMmxFilter[4 * i + 3] =
	((uint16_t) vChrFilter[chrDstY * vChrFilterSize + i]) * 0x10001U;
}}
