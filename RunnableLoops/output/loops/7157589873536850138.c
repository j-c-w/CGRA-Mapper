#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int z, uint8_t * dst, const uint8_t * xf1, const uint8_t * xf0,
    const int width)
{
  for (int x = 0; x < width; x++)
    {
      const int zx = z + x;
      const int zz = zx % width + width * (zx < 0);
      dst[x] = (zx > 0) && (zx < width) ? xf1[zz] : xf0[zz];
}}
