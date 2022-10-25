// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int A2, const int16_t ** alpSrc, int i, int lumFilterSize, int A1, int j,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      A1 += alpSrc[j][i * 2] * lumFilter[j];
      A2 += alpSrc[j][i * 2 + 1] * lumFilter[j];
    }
}
