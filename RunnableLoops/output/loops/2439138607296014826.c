#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * b0, int i, int width, int16_t * b1)
{
  for (i = 0; i < width; i++)
    {
      b0[i] = ((int) (b0[i] - (unsigned) ((int) (b1[i] + 1U) >> 1)));
      b1[i] = ((int) (b1[i] + (unsigned) (b0[i])));
}}
