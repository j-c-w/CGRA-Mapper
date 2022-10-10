#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * last, int i, int size, uint8_t * src, int bpp, uint8_t * dst)
{
  for (; i < size; i++)
    {
      dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 0xff);
    }
}
