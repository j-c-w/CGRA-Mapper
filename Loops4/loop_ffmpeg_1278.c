// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int i, int lumFilterSize, const int32_t ** alpSrc, int j, int A,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      A += alpSrc[j][i] * (unsigned) lumFilter[j];
}}
