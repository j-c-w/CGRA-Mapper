// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_fillborders.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * ptr, int y, const int width, const int linesize)
{
  for (int x = 1; x < width - 8; x++)
    {
      int prev = ptr[linesize * (y + 1) + x - 1];
      int cur = ptr[linesize * (y + 1) + x];
      int next = ptr[linesize * (y + 1) + x + 1];
      ptr[linesize * y + x] = (3 * prev + 2 * cur + 3 * next + 4) >> 3;
}}
