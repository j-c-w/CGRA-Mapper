// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (int i, uint16_t * src, const int32_t * block, uint16_t pix[8], int stride)
{
  for (i = 0; i < 8; i++)
    {
      uint16_t v = pix[i];
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
