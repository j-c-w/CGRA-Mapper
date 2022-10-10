#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int x, const int16_t * src, int w)
{
  int m = 0;
  for (x = 0; x < w; x++)
    {
      int t = src[x] + 128;
      dst[x] = t;
      m |= t;
}}
