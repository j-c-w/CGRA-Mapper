#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int width, int x, float *bptr, const uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      bptr[x] = src[x];
    }
}
