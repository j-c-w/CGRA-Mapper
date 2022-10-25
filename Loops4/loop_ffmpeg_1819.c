// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_avgblur.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (const int area, const int width, const int size_w, int32_t * col_sum,
    uint8_t * dst)
{
  int32_t sum = 0;
  for (int x = 1; x < width; x++)
    {
      sum = sum - col_sum[x - size_w - 1] + col_sum[x + size_w];
      ((void) 0);
      dst[x] = ((sum) / (area));
}}
