#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *IP, int src_stride, float maxval, float *II, int src_ref_stride,
    float *I, float *P, const uint8_t * srcRef, int sub, int w,
    const uint8_t * src)
{
  int i = 0;
  for (int j = 0; j < w; j++)
    {
      int x = i * w + j;
      I[x] = src[(i * src_stride + j) * sub] / maxval;
      II[x] = I[x] * I[x];
      P[x] = srcRef[(i * src_ref_stride + j) * sub] / maxval;
      IP[x] = I[x] * P[x];
}}
