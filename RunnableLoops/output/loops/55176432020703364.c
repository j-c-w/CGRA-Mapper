#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_pixels, const uint8_t * palette, int i, uint8_t * dst,
    const uint8_t * src)
{
  for (i = 0; i < num_pixels; i++)
    {
      dst[0] = palette[src[i << 1] * 4 + 0];
      dst[1] = palette[src[i << 1] * 4 + 1];
      dst[2] = palette[src[i << 1] * 4 + 2];
      dst += 3;
    }
}
