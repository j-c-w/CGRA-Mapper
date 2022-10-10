#include <stdint.h>
#include <stdio.h>






int
fn (int nb_samples, int n, float *dst, const float *src, float *prv)
{
  for (n = 0; n < nb_samples; n++)
    {
      const float current = src[n];
      dst[n] = current + prv[0];
      prv[0] = dst[n];
}}
