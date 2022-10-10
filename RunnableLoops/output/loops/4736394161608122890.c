#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * last, int i, int p, uint8_t * src, int bpp, uint8_t * dst)
{
  for (i = 0; i < bpp; i++)
    {
      p = (last[i] >> 1);
      dst[i] = p + src[i];
    }
}
