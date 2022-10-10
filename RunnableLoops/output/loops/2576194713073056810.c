#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * dstU, int16_t * dstV, int width, int i)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] = (dstU[i] * 1799 + 4081085) >> 11;
      dstV[i] = (dstV[i] * 1799 + 4081085) >> 11;
    }
}
