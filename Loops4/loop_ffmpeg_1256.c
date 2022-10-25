// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (const int16_t * chrFilter, const int32_t ** chrUSrc, int i,
    const int32_t ** chrVSrc, int U, int j, int chrFilterSize, int V)
{
  for (j = 0; j < chrFilterSize; j++)
    {;
      U += chrUSrc[j][i] * (unsigned) chrFilter[j];
      V += chrVSrc[j][i] * (unsigned) chrFilter[j];
}}
