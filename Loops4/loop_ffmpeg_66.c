// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_axcorrelate.c

#include <stdint.h>
#include <stdio.h>






int
fn (const double *y, const double ym, const double xm, int size,
    const double *x, double den0, double num)
{
  double den1 = 0.0;
  for (int i = 0; i < size; i++)
    {
      double xd = x[i] - xm;
      double yd = y[i] - ym;
      num += xd * yd;
      den0 += xd * xd;
      den1 += yd * yd;
}}
