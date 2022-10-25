// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lossless_videodsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t w, int i, int acc, const uint8_t * src, uint8_t * dst)
{
  for (i = 0; i < w - 1; i++)
    {
      acc += src[i];
      dst[i] = acc;
      i++;
      acc += src[i];
      dst[i] = acc;
    }
}
