#include <stdint.h>
#include <stdio.h>






int
fn (const float ym, float den0, int size, const float xm, float num,
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
