// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pixblockdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * s1, const uint8_t * s2, int i, ptrdiff_t stride,
    int16_t * __restrict block)
{
  for (i = 0; i < 8; i++)
    {
      block[0] = s1[0] - s2[0];
      block[1] = s1[1] - s2[1];
      block[2] = s1[2] - s2[2];
      block[3] = s1[3] - s2[3];
      block[4] = s1[4] - s2[4];
      block[5] = s1[5] - s2[5];
      block[6] = s1[6] - s2[6];
      block[7] = s1[7] - s2[7];
      s1 += stride;
      s2 += stride;
      block += 8;
    }
}
