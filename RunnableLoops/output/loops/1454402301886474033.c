#include <stdint.h>
#include <stdio.h>






int
fn (int src_stride, int i, int filt_w, const float *src, const float *filter)
{
  float sum = 0.f;
  int j = 0;
  for (int filt_i = 0; filt_i < filt_w; filt_i++)
    {
      const float filt_coeff = filter[filt_i];
      float img_coeff;
      int ii = i - filt_w / 2 + filt_i;
      img_coeff = src[ii * src_stride + j];
      sum += filt_coeff * img_coeff;
}}
