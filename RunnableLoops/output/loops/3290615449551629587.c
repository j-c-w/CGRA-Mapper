#include <stdint.h>
#include <stdio.h>






int
fn (float *coeffs)
{
  float sum = 0.f;
  for (int i = 0; i < 4; i++)
    {
      coeffs[i] /= sum;
}}
