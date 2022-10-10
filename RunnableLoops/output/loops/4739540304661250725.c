#include <stdint.h>
#include <stdio.h>






int
fn (const float *filter, int filt_w, float *temp)
{
  float sum = 0.f;
  int j = 0;
  for (int filt_j = 0; filt_j < filt_w; filt_j++)
    {
      const float filt_coeff = filter[filt_j];
      int jj = j - filt_w / 2 + filt_j;
      float img_coeff;
      img_coeff = temp[jj];
      sum += filt_coeff * img_coeff;
}}
