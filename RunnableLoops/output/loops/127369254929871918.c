#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int v, int y, uint16_t * dst, float o1, int height, float o2, int step,
    int linesize)
{
  for (y = 0; y < height; y += step)
    {
      dst[0] = v * o1 + dst[0] * o2;
      dst += (linesize / 2) * step;
    }
}
