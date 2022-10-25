// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (ptrdiff_t stride, const int16_t * block, uint8_t * pix, int i)
{
  for (i = 0; i < 4; i++)
    {
      uint8_t v = pix[0];
      pix[1 * stride] = v += block[0];
      pix[2 * stride] = v += block[4];
      pix[3 * stride] = v += block[8];
      pix[4 * stride] = v + block[12];
      pix++;
      block++;
    }
}
