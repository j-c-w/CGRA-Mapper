// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (ptrdiff_t stride, int i, const int32_t * block, uint16_t * pix)
{
  for (i = 0; i < 8; i++)
    {
      uint16_t v = pix[0];
      pix[1 * stride] = v += block[0];
      pix[2 * stride] = v += block[8];
      pix[3 * stride] = v += block[16];
      pix[4 * stride] = v += block[24];
      pix[5 * stride] = v += block[32];
      pix[6 * stride] = v += block[40];
      pix[7 * stride] = v += block[48];
      pix[8 * stride] = v + block[56];
      pix++;
      block++;
    }
}
