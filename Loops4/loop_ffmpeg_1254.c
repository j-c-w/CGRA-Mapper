// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * chrFilter, int i, int v, const int16_t ** chrVSrc, int u,
    const int16_t ** chrUSrc, int j, int chrFilterSize)
{
  for (j = 0; j < chrFilterSize; j++)
    {
      u += chrUSrc[j][i] * chrFilter[j];
      v += chrVSrc[j][i] * chrFilter[j];
    }
}
