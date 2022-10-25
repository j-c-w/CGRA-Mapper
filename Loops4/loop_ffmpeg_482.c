// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/zmbv.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int bw2, int i, uint8_t * src, uint16_t * out)
{
  for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint16_t *) src);
      src += 2;
    }
}
