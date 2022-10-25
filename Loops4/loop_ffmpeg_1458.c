// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_aderivative.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * prv, int16_t * dst, int nb_samples, int n, const int16_t * src)
{
  for (n = 0; n < nb_samples; n++)
    {
      const int16_t current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}}
