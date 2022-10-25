// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_midequalizer.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, int w, const uint16_t * src, float *histogram)
{
  for (x = 0; x < w; x++)
    {
      histogram[src[x]] += 1;
    }
}
