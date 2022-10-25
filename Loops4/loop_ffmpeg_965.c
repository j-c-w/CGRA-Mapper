// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_vif.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *xx, int w, float *yy, const float *y, float *xy, const float *x)
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
