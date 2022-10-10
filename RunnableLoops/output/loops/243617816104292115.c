#include <stdint.h>
#include <stdio.h>






int
fn (double *prv, double *dst, int n, int nb_samples, const double *src)
{
  for (n = 0; n < nb_samples; n++)
    {
      const double current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}}
