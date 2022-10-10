#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int width, uint8_t * dst, int x, float *bptr)
{
  for (x = 0; x < width; x++)
    {
      dst[x] = bptr[x];
    }
}
