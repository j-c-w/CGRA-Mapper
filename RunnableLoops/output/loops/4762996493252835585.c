#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int alpha, int size, int i)
{
  for (i = 0; i < size; i += 3 + alpha)
    {
      int g = dst[i + 1];
      dst[i + 0] += g;
      dst[i + 2] += g;
}}
