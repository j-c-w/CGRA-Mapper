#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * last, uint8_t * src, int size, int bpp, uint8_t * dst)
{
  for (; i < size; i++)
    {
      dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 0xff);
    }
}
