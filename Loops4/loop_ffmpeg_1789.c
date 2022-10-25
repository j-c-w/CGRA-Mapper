// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideo_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int x, int y2, int x2, int stride)
{
  int sum = 0;
  int sqr = 0;
  int count = 0;
  for (x2 = ((x - 1) > (0) ? (x - 1) : (0));
       x2 < ((8) > (x + 2) ? (x + 2) : (8)); x2++)
    {
      int v = ptr[x2 + y2 * stride];
      sum += v;
      sqr += v * v;
      count++;
}}
