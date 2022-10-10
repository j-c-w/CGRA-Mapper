#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const int64_t N, float *dst, const float *src, const float dc,
    int nb_samples)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc * (((N + n) & 1) ? -1.f : 1.f);
}}
