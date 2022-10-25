// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_aderivative.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dst, int nb_samples, int32_t * prv, int n, const int32_t * src)
{
  for (n = 0; n < nb_samples; n++)
    {
      const int32_t current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}}
