// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/huffyuvenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int g, int i, int r, uint8_t * dst, uint8_t * src, int b)
{
  for (i = 0; i < ((w) > (16) ? (16) : (w)); i++)
    {
      const int rt = src[i * 3 + 0];
      const int gt = src[i * 3 + 1];
      const int bt = src[i * 3 + 2];
      dst[i * 3 + 0] = rt - r;
      dst[i * 3 + 1] = gt - g;
      dst[i * 3 + 2] = bt - b;
      r = rt;
      g = gt;
      b = bt;
}}
