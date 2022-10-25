// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snow_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * temp, int width, IDWTELEM * b, const int w2)
{
  for (x = 1; x < (width >> 1); x++)
    {
      temp[2 * x] = b[x] - ((3 * (b[x + w2 - 1] + b[x + w2]) + 4) >> 3);
      temp[2 * x - 1] = b[x + w2 - 1] - temp[2 * x - 2] - temp[2 * x];
    }
}
