// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/avf_showspectrum.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * dst, int w)
{
  for (x = 0; x < w; x += 80)
    {
      dst[x] = 200;
    }
}
