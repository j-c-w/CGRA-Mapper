#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int k, uint8_t * srcU, uint8_t * srcV)
{
  for (i = 0; i < k; i++)
    {
      srcU[i] = ((srcU[i] - 128) >> 1) + 128;
      srcV[i] = ((srcV[i] - 128) >> 1) + 128;
    }
}
