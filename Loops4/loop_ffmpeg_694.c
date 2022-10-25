// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pngdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int alpha, uint16_t * dst, int i, int size)
{
  for (i = 0; i < size; i += 3 + alpha)
    {
      int g = dst[i + 1];
      dst[i + 0] += g;
      dst[i + 2] += g;
}}
