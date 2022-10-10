#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int i, uint8_t * dst1, int width, uint8_t * dst2)
{
  for (i = 0; i < width; i++)
    {
      dst1[i] = src[2 * i + 0];
      dst2[i] = src[2 * i + 1];
    }
}
