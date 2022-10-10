#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int x, int32_t * temp, const int w2, int32_t * b)
{
  for (x = 0; x < w2; x++)
    {
      temp[x] = ((int) (b[x] - (unsigned) ((int) (b[x + w2] + 1U) >> 1)));
      temp[x + w2] = ((int) (b[x + w2] + (unsigned) (temp[x])));
}}
