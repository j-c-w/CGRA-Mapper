// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_convolution.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int i, int radius, int x, int h, int bpc, const uint8_t * src,
    const uint8_t ** c, int stride)
{
  for (i = 0; i < radius * 2 + 1; i++)
    {
      int xoff =
	((x + i - radius) >= 0 ? (x + i - radius) : (-(x + i - radius)));
      xoff = xoff >= h ? 2 * h - 1 - xoff : xoff;
      c[i] = src + y * bpc + xoff * stride;
}}
