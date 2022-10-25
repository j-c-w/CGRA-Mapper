// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_waveform.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int v, uint16_t * dst, int x, int width, float o1, float o2, int step)
{
  for (x = 0; x < width; x += step)
    {
      dst[x] = (v - dst[x]) * o1 + dst[x] * o2;
    }
}
