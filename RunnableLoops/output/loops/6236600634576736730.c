#include <stdint.h>
#include <stdio.h>






int
fn (float r, float *lpc)
{
  int i = 0;
  for (int j = 0; j < (i + 1) >> 1; j++)
    {
      float tmp1, tmp2;
      tmp1 = lpc[j];
      tmp2 = lpc[i - 1 - j];
      lpc[j] = tmp1 + (r * tmp2);
      lpc[i - 1 - j] = tmp2 + (r * tmp1);
}}
