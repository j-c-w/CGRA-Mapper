#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int width, const uint8_t * src)
{
  for (int x = width - 4; x >= 0; x -= 2)
    {
      dst[x] = src[x >> 1];
      dst[x + 1] = (src[x >> 1] + src[(x >> 1) + 1] + 1) >> 1;
}}
