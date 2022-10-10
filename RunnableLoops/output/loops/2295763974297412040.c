#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *samples_r, float *samples_l)
{
  for (j = 0; j < 16; j++)
    {
      float tmp = samples_l[j];
      samples_l[j] = samples_r[j];
      samples_r[j] = tmp;
}}
