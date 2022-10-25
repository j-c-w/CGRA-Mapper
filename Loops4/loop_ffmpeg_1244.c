// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_bm3d.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, float *dst, int block_size, const uint16_t * src)
{
  for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
    }
}
