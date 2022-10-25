// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/4xm.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int width, unsigned int bits, int y2, unsigned int color[4], int x2,
    uint16_t * dst)
{
  for (x2 = 0; x2 < 16; x2++)
    {
      int index = 2 * (x2 >> 2) + 8 * (y2 >> 2);
      dst[y2 * width + x2] = color[(bits >> index) & 3];
}}
