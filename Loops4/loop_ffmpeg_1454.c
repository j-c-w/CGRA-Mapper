// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_aderivative.c

#include <stdint.h>
#include <stdio.h>






int
fn (double *prv, const double *src, int nb_samples, int n, double *dst)
{
  for (n = 0; n < nb_samples; n++)
    {
      const double current = src[n];
      dst[n] = current + prv[0];
      prv[0] = dst[n];
}}
