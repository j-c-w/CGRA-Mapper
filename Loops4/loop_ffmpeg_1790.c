// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dnxhdenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * pix, int j, int bw)
{
  int sum = 0;
  int sqsum = 0;
  for (j = 0; j < bw; ++j)
    {
      const int sample = (unsigned) pix[j] >> 6;
      sum += sample;
      sqsum += sample * sample;
}}
