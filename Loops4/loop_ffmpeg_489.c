// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * udst, const int chromWidth, int i, uint8_t * ydst,
    uint8_t * vdst, const uint8_t * src)
{
  for (i = 0; i < chromWidth; i++)
    {
      udst[i] = src[4 * i + 0];
      ydst[2 * i + 0] = src[4 * i + 1];
      vdst[i] = src[4 * i + 2];
      ydst[2 * i + 1] = src[4 * i + 3];
    }
}
