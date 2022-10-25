// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideoencdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * basis, unsigned int sum, int16_t * rem, int16_t * weight,
    int scale)
{
  for (i = 0; i < 8 * 8; i++)
    {
      int b = rem[i] + ((basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6));
      int w = weight[i];
      b >>= 6;
      ((void) 0);
      sum += (w * b) * (w * b) >> 4;
}}
