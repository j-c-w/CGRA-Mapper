#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int lefttop, int min_width, ptrdiff_t fake_stride, int x, int left,
    uint8_t * dst, int top)
{
  for (x = 1; x < min_width; x++)
    {
      top = dst[x - fake_stride];
      lefttop = dst[x - (fake_stride + 1)];
      left += top - lefttop + dst[x];
      dst[x] = left;
    }
}
