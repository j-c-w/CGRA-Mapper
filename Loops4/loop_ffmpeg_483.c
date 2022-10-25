// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/zmbv.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t * out, uint8_t * src, int bw2, int i)
{
  for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint32_t *) src);
      src += 4;
    }
}
