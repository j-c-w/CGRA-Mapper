#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int filterSize, int srcPos, int i, const int16_t * filter, int j,
    const uint16_t * src)
{
  int val = 0;
  for (j = 0; j < filterSize; j++)
    {
      val += src[srcPos + j] * filter[filterSize * i + j];
    }
}
