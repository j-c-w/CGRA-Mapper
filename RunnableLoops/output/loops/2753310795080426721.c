#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * pix, int j, int s, const uint32_t * sq, int w)
{
  for (j = 0; j < w; j++)
    {
      s += sq[pix[0]];
      pix++;
    }
}
