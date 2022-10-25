// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/huffyuvenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int g, int i, int min_width, int r, const uint8_t * src, int a,
    uint8_t * dst, int b)
{
  for (i = 0; i < min_width; i++)
    {
      const int rt = src[i * 4 + 2];
      const int gt = src[i * 4 + 1];
      const int bt = src[i * 4 + 0];
      const int at = src[i * 4 + 3];
      dst[i * 4 + 2] = rt - r;
      dst[i * 4 + 1] = gt - g;
      dst[i * 4 + 0] = bt - b;
      dst[i * 4 + 3] = at - a;
      r = rt;
      g = gt;
      b = bt;
      a = at;
}}
