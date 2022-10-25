// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_codecview.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, uint8_t * buf, int h, int sy, int sx, int color, int stride)
{
  for (int y = sy; y < sy + h; y++)
    {
      buf[sx] = color;
      buf[sx + w - 1] = color;
      buf += stride;
}}
