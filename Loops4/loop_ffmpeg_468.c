// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const int16_t * block, int i, uint8_t pix[8], uint8_t * src, int stride)
{
  for (i = 0; i < 8; i++)
    {
      uint8_t v = pix[i];
      src[0 * stride] = v += block[0];
      src[1 * stride] = v += block[8];
      src[2 * stride] = v += block[16];
      src[3 * stride] = v += block[24];
      src[4 * stride] = v += block[32];
      src[5 * stride] = v += block[40];
      src[6 * stride] = v += block[48];
      src[7 * stride] = v + block[56];
      src++;
      block++;
    }
}
