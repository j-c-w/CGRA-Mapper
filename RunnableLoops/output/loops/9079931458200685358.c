#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int width, int x, uint16_t * dst16, float *bptr)
{
  for (x = 0; x < width; x++)
    {
      dst16[x] = bptr[x];
    }
}
