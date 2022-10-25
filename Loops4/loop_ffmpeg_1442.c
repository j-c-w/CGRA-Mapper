// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dca_core.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __int32_t int32_t;

int
fn (int code1, int div, int offset, int levels, int n,
    const uint32_t ff_inverse[257], int32_t * audio)
{
  for (n = 0; n < 8 / 2; n++)
    {
      div = ((uint32_t) ((((uint64_t) code1) * ff_inverse[levels]) >> 32));
      audio[n] = code1 - div * levels - offset;
      code1 = div;
    }
}
