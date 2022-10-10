#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *X, float *Y, int N)
{
  for (i = 0; i < N; i++)
    {
      const float Xret = X[i];
      X[i] = (X[i] + Y[i]) * 0.70710678118654752440;
      Y[i] = (Y[i] - Xret) * 0.70710678118654752440;
}}
