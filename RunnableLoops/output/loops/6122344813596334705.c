#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dstU, int i, const uint8_t * src1, uint8_t * dstV, int width)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] = src1[4 * i + 1];
      dstV[i] = src1[4 * i + 3];
    }
}
