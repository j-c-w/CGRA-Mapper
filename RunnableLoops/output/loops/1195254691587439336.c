#include <stdint.h>
#include <stdio.h>






int
fn (int len, float tmp0, float *tab0, int j, float *tab1, float tmp1)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tmp1 = tab1[j];
      tab0[j] = ((((float) (0.70710678118654752440))) * (tmp0 + tmp1));
      tab1[j] = ((((float) (0.70710678118654752440))) * (tmp0 - tmp1));
}}
