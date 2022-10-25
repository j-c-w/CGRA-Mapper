// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int i, const int16_t * filter, int filterSize, int j, int srcPos,
    const uint16_t * src)
{
  int val = 0;
  for (j = 0; j < filterSize; j++)
    {
      val += src[srcPos + j] * filter[filterSize * i + j];
    }
}
