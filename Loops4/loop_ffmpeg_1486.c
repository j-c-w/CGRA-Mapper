// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dxtory.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, uint8_t * Y2, uint8_t * Y3, int width, uint8_t * Y4,
    const uint8_t * src, int hmargin, uint8_t * Y1)
{
  for (w = 0; w < hmargin; w++)
    {
      Y1[width + w] = src[w];
      Y2[width + w] = src[w + hmargin * 1];
      Y3[width + w] = src[w + hmargin * 2];
      Y4[width + w] = src[w + hmargin * 3];
    }
}
