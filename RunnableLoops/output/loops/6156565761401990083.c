#include <stdint.h>
#include <stdio.h>






int
fn (int len, int i, const float *src1, int j, const float *src0, float *dst,
    const float *win)
{
  for (i = -len, j = len - 1; i < 0; i++, j--)
    {
      float s0 = src0[i];
      float s1 = src1[j];
      float wi = win[i];
      float wj = win[j];
      dst[i] = s0 * wj - s1 * wi;
      dst[j] = s0 * wi + s1 * wj;
}}
