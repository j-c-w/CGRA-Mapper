#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int b, const uint8_t * src1, int x, int b_w, const uint8_t * src2,
    uint8_t * dst, int a)
{
  for (x = 0; x < b_w; x++)
    {
      dst[x] = (a * src1[x] + b * src2[x] + 4) >> 3;
    }
}