// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_adenorm.c

#include <stdint.h>
#include <stdio.h>






int
fn (int nb_samples, double *dst, const double dc, const double *src)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}}
