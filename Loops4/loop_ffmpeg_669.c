// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * src, int num_pixels, uint8_t * dst,
    const uint8_t * palette)
{
  for (i = 0; i < num_pixels; i++)
    {
      dst[0] = palette[src[i] * 4 + 0];
      dst[1] = palette[src[i] * 4 + 1];
      dst[2] = palette[src[i] * 4 + 2];
      dst += 3;
    }
}
