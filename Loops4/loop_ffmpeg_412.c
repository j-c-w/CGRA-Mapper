// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideo_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * weight, int i, int16_t rem[64], int16_t (*d1))
{
  for (i = 0; i < 64; i++)
    {
      int w = weight[i];
      d1[i] = (rem[i] * w * w + (1 << (6 + 12 - 1))) >> (6 + 12);
}}
