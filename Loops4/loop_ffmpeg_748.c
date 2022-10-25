// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snow_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * b3, int i, IDWTELEM * b2, IDWTELEM * b1, int width,
    IDWTELEM * b0, IDWTELEM * b5, IDWTELEM * b4)
{
  for (i = 0; i < width; i++)
    {
      b4[i] -= (3 * (b3[i] + b5[i]) + 4) >> 3;
      b3[i] -= (1 * (b2[i] + b4[i]) + 0) >> 0;
      b2[i] += (1 * (b1[i] + b3[i]) + 4 * b2[i] + 8) >> 4;
      b1[i] += (3 * (b0[i] + b2[i]) + 0) >> 1;
    }
}
