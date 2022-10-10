#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int V, const uint8_t * src1, int k, const uint8_t * src2, int stride)
{
  for (; k <= 8; ++k)
    {
      src1 += stride;
      src2 -= stride;
      V += k * (src1[0] - src2[0]);
    }
}
