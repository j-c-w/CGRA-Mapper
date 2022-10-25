// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * dstV, int width, int i, int16_t * dstU)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] = (dstU[i] * 1799 + 4081085) >> 11;
      dstV[i] = (dstV[i] * 1799 + 4081085) >> 11;
    }
}
