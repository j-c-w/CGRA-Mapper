#include <stdint.h>
#include <stdio.h>






int
fn (int n, float *dst, float *prv, const float *src, int nb_samples)
{
  for (n = 0; n < nb_samples; n++)
    {
      const float current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}}
