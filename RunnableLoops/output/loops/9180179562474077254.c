#include <stdint.h>
#include <stdio.h>






int
fn (const float g1, float x1, int len, float x4, const float g2,
    const float g0, float x2, float x3, float *data, int period)
{
  for (int i = 0; i < len; i++)
    {
      float x0 = data[i - period + 2];
      data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
      x4 = x3;
      x3 = x2;
      x2 = x1;
      x1 = x0;
}}
