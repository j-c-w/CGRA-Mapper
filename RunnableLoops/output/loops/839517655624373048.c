#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int width, int16_t * dst, const uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      dst[i] = src[4 * i + 3] << 6 | src[4 * i + 3] >> 2;
    }
}
