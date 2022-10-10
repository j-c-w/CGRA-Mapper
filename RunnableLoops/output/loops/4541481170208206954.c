#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, uint8_t * src, int w, int16_t * sample[3], int stride)
{
  for (x = 0; x < w; x++)
    {
      sample[0][x] = ((uint16_t *) (src + stride * y))[x];
    }
}
