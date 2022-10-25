// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_convolution.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int i, int x, int h, int bpc, const uint8_t * src,
    const uint8_t ** c, int stride)
{
  for (i = 0; i < 25; i++)
    {
      int xoff =
	((x + ((i % 5) - 2)) >=
	 0 ? (x + ((i % 5) - 2)) : (-(x + ((i % 5) - 2))));
      int yoff =
	((y + (i / 5) - 2) >= 0 ? (y + (i / 5) - 2) : (-(y + (i / 5) - 2)));
      xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
      yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
      c[i] = src + xoff * bpc + yoff * stride;
}}
