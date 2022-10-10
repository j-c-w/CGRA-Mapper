#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * d, int x, const uint8_t * up, const uint8_t * vp, int w,
    const uint8_t * yp)
{
  for (x = 0; x < w; x++)
    {
      const int x2 = x << 2;
      d[8 * x + 0] = yp[x2];
      d[8 * x + 1] = up[x];
      d[8 * x + 2] = yp[x2 + 1];
      d[8 * x + 3] = vp[x];
      d[8 * x + 4] = yp[x2 + 2];
      d[8 * x + 5] = up[x];
      d[8 * x + 6] = yp[x2 + 3];
      d[8 * x + 7] = vp[x];
}}
