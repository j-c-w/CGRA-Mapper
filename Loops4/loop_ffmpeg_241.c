// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswresample/resample_dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int dst_size, int dst_index, const double *src, int64_t incr, double *dst,
    int64_t index2)
{
  for (dst_index = 0; dst_index < dst_size; dst_index++)
    {
      dst[dst_index] = src[index2 >> 32];
      index2 += incr;
    }
}
