#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int width, uint32_t x, const uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      dst[x] = *src;
      src += 2;
    }
}
