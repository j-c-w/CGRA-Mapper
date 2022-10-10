#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * src2, int y, int x, uint8_t * src1, const uint32_t * sq, int w,
    int stride)
{
  int acc = 0;
  for (x = 0; x < w; x++)
    {
      acc += sq[src1[x + y * stride] - src2[x + y * stride]];
    }
}
