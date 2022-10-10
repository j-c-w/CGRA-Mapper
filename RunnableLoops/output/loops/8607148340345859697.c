#include <stdint.h>
#include <stdio.h>






int
fn (float *xy, float *xx, float *yy, const float *x, const float *y, int w)
{
  for (int j = 0; j < w; j++)
    {
      float xval = x[j];
      float yval = y[j];
      float xxval = xval * xval;
      float yyval = yval * yval;
      float xyval = xval * yval;
      xx[j] = xxval;
      yy[j] = yyval;
      xy[j] = xyval;
}}
