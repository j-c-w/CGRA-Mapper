// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speexdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *exc, float pitch_coef, int nsf, int start, float *exc_out)
{
  for (int i = 0; i < nsf; i++)
    {
      exc_out[i] = exc[i - start] * pitch_coef;
      exc[i] = exc_out[i];
}}
