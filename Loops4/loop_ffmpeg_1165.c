// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_nlmeans.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * s1, int w, const uint32_t * dst_top, const uint8_t * s2,
    uint32_t * dst)
{
  for (int x = 0; x < w; x += 4)
    {
      const int d0 = s1[x] - s2[x];
      const int d1 = s1[x + 1] - s2[x + 1];
      const int d2 = s1[x + 2] - s2[x + 2];
      const int d3 = s1[x + 3] - s2[x + 3];
      dst[x] = dst_top[x] - dst_top[x - 1] + d0 * d0;
      dst[x + 1] = dst_top[x + 1] - dst_top[x] + d1 * d1;
      dst[x + 2] = dst_top[x + 2] - dst_top[x + 1] + d2 * d2;
      dst[x + 3] = dst_top[x + 3] - dst_top[x + 2] + d3 * d3;
      dst[x] += dst[x - 1];
      dst[x + 1] += dst[x];
      dst[x + 2] += dst[x + 1];
      dst[x + 3] += dst[x + 2];
}}
