#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int num_pixels, int i, const uint8_t * src)
{
  for (i = 0; i < num_pixels; i++)
    {
      dst[3 * i + 0] = src[4 * i + 2];
      dst[3 * i + 1] = src[4 * i + 1];
      dst[3 * i + 2] = src[4 * i + 0];
    }
}
