#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int x, int srcWidth, const uint8_t * src)
{
  for (x = 0; x < srcWidth - 1; x++)
    {
      dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
      dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
    }
}
