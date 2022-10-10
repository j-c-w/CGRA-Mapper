#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int v, uint16_t * dst, int x, float o2, int width, float o1, int step)
{
  for (x = 0; x < width; x += step)
    {
      dst[x] = (v - dst[x]) * o1 + dst[x] * o2;
    }
}
