#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * dstPtr2, int length, const uint8_t * dither,
    const uint16_t * srcPtr2, int j, unsigned int tmp, const int dst_depth,
    unsigned int shift)
{
  for (; j < length; j++)
    {
      tmp = (srcPtr2[j]);
      dstPtr2[j] = ((tmp - (tmp >> dst_depth) + dither[j & 7]) >> shift);
    }
}
