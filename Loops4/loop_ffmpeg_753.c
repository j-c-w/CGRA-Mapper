// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int width, int32_t * dstU, int32_t * dstV, int i)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] = (dstU[i] * 1799 + (4081085 << 4)) >> 11;
      dstV[i] = (dstV[i] * 1799 + (4081085 << 4)) >> 11;
    }
}
