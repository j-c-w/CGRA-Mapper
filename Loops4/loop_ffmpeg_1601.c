// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int scale_low, uint16_t * dest, int x, int width, int scale_high,
    const uint16_t ** src)
{
  for (x = 0; x < width; x++)
    {
      *dest++ = src[0][x] << scale_high | src[0][x] >> scale_low;
      *dest++ = src[1][x] << scale_high | src[1][x] >> scale_low;
      *dest++ = src[2][x] << scale_high | src[2][x] >> scale_low;
    }
}
