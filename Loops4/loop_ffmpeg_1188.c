// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_avgblur.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint16_t uint16_t;

int
fn (const int width, int64_t sum, const int size_w, int64_t * col_sum,
    const uint16_t * lut, uint16_t * dst)
{
  for (int x = 1; x < width; x++)
    {
      sum = sum - col_sum[x - size_w - 1] + col_sum[x + size_w];
      ((void) 0);
      dst[x] = (lut[(sum)]);
}}
