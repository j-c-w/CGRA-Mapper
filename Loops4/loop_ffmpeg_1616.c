// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/hnm4video.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int width, uint8_t * dst, const uint8_t * src, uint32_t x)
{
  for (x = 0; x < width; x++)
    {
      dst[x] = *src;
      src += 2;
    }
}
