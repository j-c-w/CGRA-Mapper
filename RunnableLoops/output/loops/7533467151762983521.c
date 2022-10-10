#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * dst, int n, int16_t * prv, const int16_t * src, int nb_samples)
{
  for (n = 0; n < nb_samples; n++)
    {
      const int16_t current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}}
