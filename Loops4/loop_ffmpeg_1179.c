// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_xfade.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int height, int y, int zw, float progress, const int width, int zh,
    const uint16_t * xf1, const uint16_t * xf0, uint16_t * dst, const int bg)
{
  for (int x = 0; x < width; x++)
    {
      int dist =
	((x - width / 2) >= 0 ? (x - width / 2) : (-(x - width / 2))) < zw
	&& ((y - height / 2) >= 0 ? (y - height / 2) : (-(y - height / 2))) <
	zh;
      int val = progress < 0.5f ? xf1[x] : xf0[x];
      dst[x] = !dist ? bg : val;
}}
