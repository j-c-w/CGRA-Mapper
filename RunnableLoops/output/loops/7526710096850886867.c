#include <stdint.h>
#include <stdio.h>






int
fn (const double dc, int nb_samples, double *dst, const double *src)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}}
