// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flacdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * samples, int i, int len, int32_t ** in, int shift)
{
  for (i = 0; i < len; i++)
    {
      unsigned a = in[0][i];
      unsigned b = in[1][i];
      (*samples++) = a << shift;
      (*samples++) = (a - b) << shift;
}}
