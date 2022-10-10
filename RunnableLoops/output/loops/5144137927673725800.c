#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int y, int x, const uint32_t * sq, uint8_t * src1, uint8_t * src2, int w,
    int stride)
{
  int acc = 0;
  for (x = 0; x < w; x++)
    {
      acc += sq[src1[x + y * stride] - src2[x + y * stride]];
    }
}
