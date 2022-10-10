#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *diff_isf, float sum, int lag, float mean)
{
  for (i = 7; i < 16 - 2; i++)
    {
      float prod = (diff_isf[i] - mean) * (diff_isf[i - lag] - mean);
      sum += prod * prod;
}}
