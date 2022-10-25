// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/output.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t ** alpSrc, int lumFilterSize, int j,
    const int16_t * lumFilter)
{
  int A = 0;
  for (j = 0; j < lumFilterSize; j++)
    {
      A += alpSrc[j][i] * lumFilter[j];
    }
}
