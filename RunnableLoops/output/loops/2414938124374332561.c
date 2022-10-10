#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float *IP, int src_stride, const uint16_t * srcRef, float maxval,
    float *II, float *I, int src_ref_stride, float *P, const uint16_t * src,
    int sub, int w)
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
