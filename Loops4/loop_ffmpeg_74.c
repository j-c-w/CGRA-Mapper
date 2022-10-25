// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_aiir.c

#include <stdint.h>
#include <stdio.h>






int
fn (double a1, double *y, double b1, double w1, double b0, double a2,
    int length, double b2, double *x)
{
  double w2 = 0.;
  for (int n = 0; n < length; n++)
    {
      double out, in = x[n];
      y[n] = out = in * b0 + w1;
      w1 = b1 * in + w2 + a1 * out;
      w2 = b2 * in + a2 * out;
}}
