#include <stdint.h>
#include <stdio.h>






int
fn (float den0, const float ym, int size, const float xm, float num,
    const float *x, const float *y)
{
  float den1 = 0.f;
  for (int i = 0; i < size; i++)
    {
      float xd = x[i] - xm;
      float yd = y[i] - ym;
      num += xd * yd;
      den0 += xd * xd;
      den1 += yd * yd;
}}
