// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int width, uint8_t * dst1, const uint8_t * src, uint8_t * dst2)
{
  for (w = 0; w < width; w++)
    {
      dst1[w] = src[2 * w + 0];
      dst2[w] = src[2 * w + 1];
    }
}
