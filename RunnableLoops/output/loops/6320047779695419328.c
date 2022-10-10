#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * dstU, int16_t * dstV, int width, int i)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] =
	(((dstU[i]) > (30775) ? (30775) : (dstU[i])) * 4663 - 9289992) >> 12;
      dstV[i] =
	(((dstV[i]) > (30775) ? (30775) : (dstV[i])) * 4663 - 9289992) >> 12;
    }
}
