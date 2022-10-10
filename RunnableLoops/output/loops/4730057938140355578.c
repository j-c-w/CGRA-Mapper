#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int x, int w)
{
  for (x = 0; x < w; x += 80)
    {
      dst[x] = 200;
    }
}
