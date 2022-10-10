#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * lut2, int i, int k, uint8_t * srcU, uint8_t * srcV)
{
  for (i = 0; i < k; i++)
    {
      srcU[i] = lut2[srcU[i]];
      srcV[i] = lut2[srcV[i]];
    }
}
