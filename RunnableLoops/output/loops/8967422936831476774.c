#include <stdint.h>
#include <stdio.h>






int
fn (const float *y01, const float *y02, float xy02, const float *x,
    float xy01, int N)
{
  for (int i = 0; i < N; i++)
    {
      xy01 += (x[i] * y01[i]);
      xy02 += (x[i] * y02[i]);
}}
