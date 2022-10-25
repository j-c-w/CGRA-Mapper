// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_v360.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *coeffs)
{
  float sum = 0.f;
  for (int i = 0; i < 4; i++)
    {
      coeffs[i] /= sum;
}}
