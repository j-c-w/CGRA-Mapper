// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/amrwbdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *diff_isf, int i, int lag, float mean, float sum)
{
  for (i = 7; i < 16 - 2; i++)
    {
      float prod = (diff_isf[i] - mean) * (diff_isf[i - lag] - mean);
      sum += prod * prod;
}}
