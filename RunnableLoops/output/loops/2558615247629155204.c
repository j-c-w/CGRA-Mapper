#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint8_t * dstPtr, int length, const uint8_t * dither,
    const uint16_t * srcPtr2, int j, unsigned int tmp, const int dst_depth,
    unsigned int shift)
{
  for (; j < length; j++)
    {
      tmp = ((srcPtr2[j]) + dither[j & 7]) >> shift;
      dstPtr[j] = (tmp - (tmp >> dst_depth));
    }
}
