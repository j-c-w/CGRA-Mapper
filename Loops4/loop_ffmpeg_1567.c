// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_premultiply.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *asrc, int w, const float *msrc, int x, float *dst)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = msrc[x] * asrc[x];
    }
}
