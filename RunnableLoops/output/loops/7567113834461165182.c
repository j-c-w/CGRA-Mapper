#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int x, int w, const uint8_t * src)
{
  for (x = w - 1; (x + 1) & 7; x--)
    {
      dst[x] = src[(x >> 1)];
    }
}
