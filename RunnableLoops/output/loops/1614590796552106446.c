#include <stdint.h>
#include <stdio.h>






int
fn (const float dc, float *dst, int nb_samples, const float *src)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}}
