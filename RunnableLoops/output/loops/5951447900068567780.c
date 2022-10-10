#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t b, uint8_t * data, int y, int x, int height, int linesize,
    uint8_t g, uint8_t r)
{
  for (y = 0; y < height; y++)
    {
      data[linesize * y + 4 * x] = r;
      data[linesize * y + 4 * x + 1] = g;
      data[linesize * y + 4 * x + 2] = b;
    }
}
