#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t b, int i, uint8_t * dst1, uint8_t * src1, uint8_t a,
    uint8_t * src2, int w, uint8_t * dst2)
{
  for (i = (w - 1) >> 1; i >= 0; i--)
    {
      a = src1[i];
      b = src2[i];
      dst1[i] = (3 * a + b + 2) >> 2;
      dst2[i] = (a + 3 * b + 2) >> 2;
    }
}
