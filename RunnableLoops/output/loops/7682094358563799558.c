#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, int w, uint8_t * pix, int s)
{
  for (j = 0; j < w; j++)
    {
      s += pix[0];
      pix++;
    }
}
