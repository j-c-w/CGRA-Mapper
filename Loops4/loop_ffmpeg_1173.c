// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_convolve.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * src, const int w, float total)
{
  for (int x = 0; x < w; x++)
    {
      total += src[x];
}}
