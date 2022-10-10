#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src1, int i, uint8_t * dstU, uint8_t * dstV, int width)
{
  for (i = 0; i < width; i++)
    {
      dstV[i] = src1[4 * i + 1];
      dstU[i] = src1[4 * i + 3];
    }
}
