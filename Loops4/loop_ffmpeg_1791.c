// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideo_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * weight, int i)
{
  int sum = 1;
  for (i = 0; i < 64; i++)
    {
      int one = 36;
      int qns = 4;
      int w;
      w = ((weight[i]) >= 0 ? (weight[i]) : (-(weight[i]))) + qns * one;
      w = 15 + (48 * qns * one + w / 2) / w;
      weight[i] = w;
      ((void) 0);
      ((void) 0);
      sum += w * w;
}}
