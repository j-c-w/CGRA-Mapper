// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * chrFilter, int i, const int16_t ** chrVSrc, int U,
    const int16_t ** chrUSrc, int j, int chrFilterSize, int V)
{
  for (j = 0; j < chrFilterSize; j++)
    {
      U += chrUSrc[j][i] * chrFilter[j];
      V += chrVSrc[j][i] * chrFilter[j];
    }
}
