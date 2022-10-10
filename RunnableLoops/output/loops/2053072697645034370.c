#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t * pal, int16_t * dst, int i, int width, const uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      int d = src[i];
      dst[i] = (pal[d] >> 24) << 6 | pal[d] >> 26;
}}
