// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, const int16_t * block, uint8_t * pix, int i)
{
  for (i = 0; i < 4; i++)
    {
      uint8_t v = pix[-1];
      pix[0] = v += block[0];
      pix[1] = v += block[1];
      pix[2] = v += block[2];
      pix[3] = v + block[3];
      pix += stride;
      block += 4;
    }
}
