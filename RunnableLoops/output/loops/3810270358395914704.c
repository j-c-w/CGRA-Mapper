#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, int y, int height, float o2, float o1, uint8_t * dst, int linesize,
    int step)
{
  for (y = 0; y < height; y += step)
    {
      dst[0] = v * o1 + dst[0] * o2;
      dst += linesize * step;
    }
}
