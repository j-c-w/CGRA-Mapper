#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int x, int w, const uint8_t * src)
{
  for (; x < w; x++)
    {
      dst[x] = src[2 * x];
    }
}
