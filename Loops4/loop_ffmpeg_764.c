// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/magicyuvenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t prev, const uint8_t * src, uint8_t * dst)
{
  for (i = 0; i < width; i++)
    {
      dst[i] = src[i] - prev;
      prev = src[i];
    }
}
