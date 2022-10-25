// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/huffyuvdsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int intptr_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t a, uint8_t r, int i, uint8_t g, intptr_t w, const uint8_t * src,
    uint8_t * dst, uint8_t b)
{
  for (i = 0; i < w; i++)
    {
      b += src[4 * i + 0];
      g += src[4 * i + 1];
      r += src[4 * i + 2];
      a += src[4 * i + 3];
      dst[4 * i + 0] = b;
      dst[4 * i + 1] = g;
      dst[4 * i + 2] = r;
      dst[4 * i + 3] = a;
    }
}
