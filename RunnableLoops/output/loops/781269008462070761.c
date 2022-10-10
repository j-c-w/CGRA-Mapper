#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, uint8_t * dst1, int width, int w, uint8_t * dst2)
{
  for (w = 0; w < width; w++)
    {
      dst1[w] = src[2 * w + 0];
      dst2[w] = src[2 * w + 1];
    }
}
