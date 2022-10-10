#include <stdint.h>
#include <stdio.h>






int
fn (int filt_w, const float *filter, int w, float *temp)
{
  float sum = 0.f;
  int j = 0;
  for (int filt_j = 0; filt_j < filt_w; filt_j++)
    {
      const float filt_coeff = filter[filt_j];
      int jj = j - filt_w / 2 + filt_j;
      float img_coeff;
      jj = jj < 0 ? -jj : (jj >= w ? 2 * w - jj - 1 : jj);
      img_coeff = temp[jj];
      sum += filt_coeff * img_coeff;
}}
