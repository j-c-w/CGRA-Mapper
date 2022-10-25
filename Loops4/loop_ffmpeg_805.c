// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/utvideodec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int min_width, int B, int C, int A,
    uint8_t * bsrc)
{
  for (i = 1; i < min_width; i++)
    {
      A = bsrc[i - stride];
      B = bsrc[i - (stride + 1)];
      C = bsrc[i - 1];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
    }
}
