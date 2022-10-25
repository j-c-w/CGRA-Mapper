// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_waveform.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int y, int v, uint16_t * dst, float o1, int linesize, float o2, int step,
    int height)
{
  for (y = 0; y < height; y += step)
    {
      dst[0] = (v - dst[0]) * o1 + dst[0] * o2;
      dst += (linesize / 2) * step;
    }
}
