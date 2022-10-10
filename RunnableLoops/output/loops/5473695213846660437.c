#include <stdint.h>
#include <stdio.h>






int
fn (const float *const spectral, float num, int size, const float scale)
{
  float den = 0.f;
  for (int n = 0; n < size; n++)
    {
      num += spectral[n] * n * scale;
      den += spectral[n];
}}
