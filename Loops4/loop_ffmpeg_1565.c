// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_premultiply.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int x, const uint16_t * msrc, int half, int shift,
    const uint16_t * asrc, uint16_t * dst)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + half) >> shift;
    }
}
