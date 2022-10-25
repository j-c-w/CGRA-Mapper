// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const int16_t * block, int i, uint8_t pix[8], uint8_t * src, int stride)
{
  for (i = 0; i < 8; i++)
    {
      uint8_t v = pix[i];
      src[0] = v += block[0];
      src[1] = v += block[1];
      src[2] = v += block[2];
      src[3] = v += block[3];
      src[4] = v += block[4];
      src[5] = v += block[5];
      src[6] = v += block[6];
      src[7] = v + block[7];
      src += stride;
      block += 8;
    }
}
