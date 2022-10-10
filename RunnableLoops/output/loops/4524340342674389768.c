#include <stdint.h>
#include <stdio.h>






int
fn (int i, int j, int N0, float *X, int stride)
{
  for (j = 0; j < N0; j++)
    {
      float x0 = X[stride * (2 * j + 0) + i];
      float x1 = X[stride * (2 * j + 1) + i];
      X[stride * (2 * j + 0) + i] = (x0 + x1) * 0.70710678118654752440;
      X[stride * (2 * j + 1) + i] = (x0 - x1) * 0.70710678118654752440;
}}
