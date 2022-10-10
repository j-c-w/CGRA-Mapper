#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * xf1, const uint16_t * xf0, const int bg,
    const int height, int y, uint16_t * dst, int zh, float progress,
    const int width, int zw)
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
