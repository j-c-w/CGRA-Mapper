#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, int x, float o2, int width, float o1, uint8_t * dst, int step)
{
  for (x = 0; x < width; x += step)
    {
      dst[x] = (v - dst[x]) * o1 + dst[x] * o2;
    }
}
