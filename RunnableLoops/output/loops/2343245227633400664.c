#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dstV, int i, int width, int32_t * dstU)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
      dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
    }
}
