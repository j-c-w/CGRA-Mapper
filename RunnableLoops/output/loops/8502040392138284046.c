#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int width, int16_t * low, int16_t * high)
{
  for (int i = 0; i < width; i++)
    {
      int even = (low[i] - high[i]) / 2;
      int odd = (low[i] + high[i]) / 2;
      low[i] = even;
      high[i] = odd;
}}
