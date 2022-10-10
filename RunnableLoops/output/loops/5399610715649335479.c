#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t prev, int i, uint8_t * src, int width, uint8_t * dst)
{
  for (i = 0; i < width; i++)
    {
      *dst++ = src[i] - prev;
      prev = src[i];
    }
}
