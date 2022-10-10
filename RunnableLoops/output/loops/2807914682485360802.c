#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int left, int width, uint8_t * dst, const uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      dst[i] = src[i] - left;
      left = src[i];
    }
}
