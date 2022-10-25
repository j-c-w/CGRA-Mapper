// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/magicyuv.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * r, uint16_t * b, uint16_t * g, int width, int k, const int max)
{
  for (k = 0; k < width; k++)
    {
      b[k] = (b[k] + g[k]) & max;
      r[k] = (r[k] + g[k]) & max;
    }
}
