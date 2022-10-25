// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_vmafmotion.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int i, int radius, const uint16_t * filter, int k, int filt_w,
    ptrdiff_t src_stride, int j, const uint16_t * src)
{
  int sum = 0;
  for (k = 0; k < filt_w; k++)
    {
      sum += filter[k] * src[i * src_stride + j - radius + k];
    }
}
