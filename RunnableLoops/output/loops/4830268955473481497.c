#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int i, int bpc, int x, int radius, const uint8_t ** c, int h,
    int stride, const uint8_t * src)
{
  for (i = 0; i < radius * 2 + 1; i++)
    {
      int xoff =
	((x + i - radius) >= 0 ? (x + i - radius) : (-(x + i - radius)));
      xoff = xoff >= h ? 2 * h - 1 - xoff : xoff;
      c[i] = src + y * bpc + xoff * stride;
}}
