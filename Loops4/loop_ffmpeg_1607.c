// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_gblur.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * src16, int x, const int width, float *bptr)
{
  for (x = 0; x < width; x++)
    {
      bptr[x] = src16[x];
    }
}
