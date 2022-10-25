// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int num_pixels, uint8_t * dst, int i)
{
  for (i = 0; i < num_pixels; i++)
    {
      dst[3 * i + 0] = src[4 * i + 2];
      dst[3 * i + 1] = src[4 * i + 1];
      dst[3 * i + 2] = src[4 * i + 0];
    }
}
