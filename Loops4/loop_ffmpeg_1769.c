// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_tmidequalizer.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *const h2, int hsize, int k, int p2[256],
    const float *const h1)
{
  int p1 = 0;
  for (; p2[k] < hsize && h2[p2[k]] < h1[p1]; p2[k]++);
}
