#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, int y, float o1, int height, float o2, int step, uint8_t * dst,
    int linesize)
{
  for (y = 0; y < height; y += step)
    {
      dst[0] = (v - dst[0]) * o1 + dst[0] * o2;
      dst += linesize * step;
    }
}
