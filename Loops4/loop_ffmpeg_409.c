// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dvdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint16_t * iweight2, int i, uint32_t * factor2, int c,
    const uint16_t * iweight1, const uint8_t dv100_qstep[16], int s,
    uint32_t * factor1)
{
  for (i = 0; i < 64; i++)
    {
      *factor1++ = (dv100_qstep[s] << (c + 9)) * iweight1[i];
      *factor2++ = (dv100_qstep[s] << (c + 9)) * iweight2[i];
    }
}
