// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_convolution.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int i, int radius, int x, int bpc, const uint8_t * src,
    const uint8_t ** c, int stride)
{
  for (i = 0; i < radius * 2 + 1; i++)
    {
      int xoff =
	((x + i - radius) >= 0 ? (x + i - radius) : (-(x + i - radius)));
      xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
      c[i] = src + xoff * bpc + y * stride;
}}
