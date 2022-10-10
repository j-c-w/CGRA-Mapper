#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src1, uint8_t * dest, int width, const uint8_t * src2,
    int w)
{
  for (w = 0; w < width; w++)
    {
      dest[2 * w + 0] = src1[w];
      dest[2 * w + 1] = src2[w];
    }
}
