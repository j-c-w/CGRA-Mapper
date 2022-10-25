// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_xfade.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * xf0, const int size, const uint16_t * xf1)
{
  float sum1 = 0.f;
  float sum0 = 0.f;
  for (int x = 0; x < size; x++)
    {
      sum0 += xf0[x];
      sum1 += xf1[x];
}}
