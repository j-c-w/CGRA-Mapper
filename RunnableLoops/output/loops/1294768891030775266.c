#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int src_size, uint8_t * dst, int i, const uint8_t * src)
{
  for (i = 0; 3 * i < src_size; i++)
    {
      dst[4 * i + 0] = src[3 * i + 2];
      dst[4 * i + 1] = src[3 * i + 1];
      dst[4 * i + 2] = src[3 * i + 0];
      dst[4 * i + 3] = 255;
    }
}
