#include <stdint.h>
#include <stdio.h>






int
fn (int i, float side, float *X, float *Y, float xp, int N)
{
  for (i = 0; i < N; i++)
    {
      xp += X[i] * Y[i];
      side += Y[i] * Y[i];
    }
}
