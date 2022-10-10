#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t prev, int i, int width, uint8_t * dst, const uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      dst[i] = src[i] - prev;
      prev = src[i];
    }
}
