#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dst, int n, int32_t * prv, const int32_t * src, int nb_samples)
{
  for (n = 0; n < nb_samples; n++)
    {
      const int32_t current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}}
