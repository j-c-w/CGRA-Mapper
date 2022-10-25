// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_crossfeed.c

#include <stdint.h>
#include <stdio.h>






int
fn (double a1, const double *src, double w2, int nb_samples, double a2,
    double b0, double w1, double b1, double *dst, double b2)
{
  for (int n = 0; n < nb_samples; n++)
    {
      double side = src[n];
      double oside = side * b0 + w1;
      w1 = b1 * side + w2 + a1 * oside;
      w2 = b2 * side + a2 * oside;
      dst[n] = oside;
}}
