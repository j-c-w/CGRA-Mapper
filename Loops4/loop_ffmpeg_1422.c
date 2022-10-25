// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/avf_showwaves.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, int end, int k, const uint8_t * color, int linesize,
    int start)
{
  for (k = start + 1; k < end; k++)
    {
      buf[k * linesize + 0] += color[0];
      buf[k * linesize + 1] += color[1];
      buf[k * linesize + 2] += color[2];
      buf[k * linesize + 3] += color[3];
    }
}
