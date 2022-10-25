// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (ptrdiff_t stride, int i, const int32_t * block, uint16_t * pix)
{
  for (i = 0; i < 4; i++)
    {
      uint16_t v = pix[-1];
      pix[0] = v += block[0];
      pix[1] = v += block[1];
      pix[2] = v += block[2];
      pix[3] = v + block[3];
      pix += stride;
      block += 4;
    }
}
