#include <stdint.h>
#include <stdio.h>






int
fn (float *dst, const float *src, int nb_samples, const float dc)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}}
