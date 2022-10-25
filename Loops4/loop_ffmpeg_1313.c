// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snowenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * pix, int w, const uint32_t * sq, int s, int j)
{
  for (j = 0; j < w; j++)
    {
      s += sq[pix[0]];
      pix++;
    }
}
