// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snow_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * b3, IDWTELEM * b2, IDWTELEM * b1, int x, int width,
    IDWTELEM * b0)
{
  for (x = 0; x < width; x++)
    {
      b2[x] -= (b1[x] + b3[x] + 2) >> 2;
      b1[x] += (b0[x] + b2[x]) >> 1;
    }
}
