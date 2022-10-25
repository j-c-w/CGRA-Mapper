// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int src_size, int i, const uint8_t * src, uint8_t * dst)
{
  for (i = 0; i < src_size; i += 4)
    {
      dst[i + 0] = src[i + 3];
      dst[i + 1] = src[i + 2];
      dst[i + 2] = src[i + 1];
      dst[i + 3] = src[i + 0];
    }
}
