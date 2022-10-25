// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavs.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * left, int x, uint8_t * top)
{
  int ih = 0;
  int iv = 0;
  for (x = 0; x < 4; x++)
    {
      ih += (x + 1) * (top[5 + x] - top[3 - x]);
      iv += (x + 1) * (left[5 + x] - left[3 - x]);
    }
}
