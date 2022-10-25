// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (const int32_t ** uSrc, const int16_t * chrFilter, const int32_t ** vSrc,
    int i, int v, int u, int j, int chrFilterSize)
{
  for (j = 0; j < chrFilterSize; j++)
    {
      u += uSrc[j][i] * (unsigned) chrFilter[j];
      v += vSrc[j][i] * (unsigned) chrFilter[j];
}}
