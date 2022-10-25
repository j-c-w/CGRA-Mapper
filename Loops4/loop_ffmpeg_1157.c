// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_adenorm.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const double *src, int nb_samples, const int64_t N, double *dst,
    const double dc)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc * ((((N + n) >> 8) & 1) ? -1. : 1.);
}}
