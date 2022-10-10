#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float *exponents, int esize, int bsize, float e2, float v)
{
  for (i = 0; i < n; i++)
    {
      v = exponents[i << bsize >> esize];
      e2 += v * v;
    }
}
