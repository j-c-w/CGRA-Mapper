#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int alpha, int i, uint16_t * dst, int size)
{
  for (i = 0; i < size; i += 3 + alpha)
    {
      int g = dst[i + 1];
      dst[i + 0] += g;
      dst[i + 2] += g;
}}
