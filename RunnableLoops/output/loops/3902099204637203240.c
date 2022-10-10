#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (float s, uint32_t stride, int i, float c, float *Xptr, uint32_t len)
{
  for (i = len - 2 * stride - 1; i >= 0; i--)
    {
      float x1 = Xptr[0];
      float x2 = Xptr[stride];
      Xptr[stride] = c * x2 + s * x1;
      *Xptr-- = c * x1 - s * x2;
}}
