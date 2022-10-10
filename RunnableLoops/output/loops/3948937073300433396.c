#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * xf1, const uint16_t * xf0, const int z, uint16_t * dst,
    const int width)
{
  for (int x = 0; x < width; x++)
    {
      const int zx = z + x;
      const int zz = zx % width + width * (zx < 0);
      dst[x] = (zx > 0) && (zx < width) ? xf1[zz] : xf0[zz];
}}
