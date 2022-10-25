// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_rotate.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst_color, int i, int int_y1, int int_x1, int src_linestep,
    int int_y, int src_linesize, int frac_y, int frac_x, const uint8_t * src,
    int int_x)
{
  for (i = 0; i < src_linestep; i++)
    {
      int s00 = src[src_linestep * int_x + i + src_linesize * int_y];
      int s01 = src[src_linestep * int_x1 + i + src_linesize * int_y];
      int s10 = src[src_linestep * int_x + i + src_linesize * int_y1];
      int s11 = src[src_linestep * int_x1 + i + src_linesize * int_y1];
      int s0 = (((1 << 16) - frac_x) * s00 + frac_x * s01);
      int s1 = (((1 << 16) - frac_x) * s10 + frac_x * s11);
      dst_color[i] =
	((int64_t) ((1 << 16) - frac_y) * s0 + (int64_t) frac_y * s1) >> 32;
}}
