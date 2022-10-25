// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_midequalizer.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (int x, size_t hsize, float *histogram)
{
  for (x = 0; x < hsize - 1; x++)
    {
      histogram[x + 1] += histogram[x];
      histogram[x] /= hsize;
    }
}
