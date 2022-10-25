// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int A2, int i, int j, const int32_t ** alpSrc, int A1, int lumFilterSize,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      A1 += alpSrc[j][i * 2] * (unsigned) lumFilter[j];
      A2 += alpSrc[j][i * 2 + 1] * (unsigned) lumFilter[j];
}}
