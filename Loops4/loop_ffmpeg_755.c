// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t * dstU, const uint8_t * src1, uint8_t * dstV)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] = src1[4 * i + 0];
      dstV[i] = src1[4 * i + 2];
    }
}
