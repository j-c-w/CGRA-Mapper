// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv40dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t * ptr, int i, int sum_p1p0, ptrdiff_t stride, uint8_t * src,
    int sum_q1q0, int step)
{
  for (i = 0, ptr = src; i < 4; i++, ptr += stride)
    {
      sum_p1p0 += ptr[-2 * step] - ptr[-1 * step];
      sum_q1q0 += ptr[1 * step] - ptr[0 * step];
    }
}
