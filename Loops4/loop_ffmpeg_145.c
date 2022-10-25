// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int V, const uint16_t * src2, const uint16_t * src1, int k, int stride)
{
  for (; k <= 8; ++k)
    {
      src1 += stride;
      src2 -= stride;
      V += k * (src1[0] - src2[0]);
    }
}
