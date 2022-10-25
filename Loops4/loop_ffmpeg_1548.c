// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/gdv.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * dst, int w, const uint8_t * src)
{
  for (x = 0; x < w - 7; x += 8)
    {
      dst[x + 0] = src[2 * x + 0];
      dst[x + 1] = src[2 * x + 2];
      dst[x + 2] = src[2 * x + 4];
      dst[x + 3] = src[2 * x + 6];
      dst[x + 4] = src[2 * x + 8];
      dst[x + 5] = src[2 * x + 10];
      dst[x + 6] = src[2 * x + 12];
      dst[x + 7] = src[2 * x + 14];
    }
}
