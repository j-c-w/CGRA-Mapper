// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** lumSrc, int i, const int16_t * lumFilter,
    int lumFilterSize, int Y1, int j, int Y2)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      Y1 += lumSrc[j][i * 2] * lumFilter[j];
      Y2 += lumSrc[j][i * 2 + 1] * lumFilter[j];
    }
}
