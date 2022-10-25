// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_waveform.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int v, float o1, int linesize, uint8_t * dst, float o2, int step,
    int height)
{
  for (y = 0; y < height; y += step)
    {
      dst[0] = (v - dst[0]) * o1 + dst[0] * o2;
      dst += linesize * step;
    }
}
