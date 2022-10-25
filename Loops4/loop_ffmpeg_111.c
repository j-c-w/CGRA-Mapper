// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pngdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * last, int size, int bpp, uint8_t * dst, uint8_t * src)
{
  for (; i < size; i++)
    {
      dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 0xff);
    }
}
