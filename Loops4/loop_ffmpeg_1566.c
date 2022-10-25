// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_premultiply.c

#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *asrc, const float *msrc, int x, float *dst,
    float offsetf)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = ((msrc[x] - offsetf) * asrc[x]) + offsetf;
    }
}
