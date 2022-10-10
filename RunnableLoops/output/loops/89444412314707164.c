#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * dstPtr2, int length, const uint8_t * dither,
    const uint16_t * srcPtr2, int j, unsigned int tmp, const int dst_depth,
    unsigned int shift)
{
  for (j = 0; j < length - 7; j += 8)
    {
      tmp = (srcPtr2[j + 0]);
      dstPtr2[j + 0] = ((tmp - (tmp >> dst_depth) + dither[0]) >> shift);
      tmp = (srcPtr2[j + 1]);
      dstPtr2[j + 1] = ((tmp - (tmp >> dst_depth) + dither[1]) >> shift);
      tmp = (srcPtr2[j + 2]);
      dstPtr2[j + 2] = ((tmp - (tmp >> dst_depth) + dither[2]) >> shift);
      tmp = (srcPtr2[j + 3]);
      dstPtr2[j + 3] = ((tmp - (tmp >> dst_depth) + dither[3]) >> shift);
      tmp = (srcPtr2[j + 4]);
      dstPtr2[j + 4] = ((tmp - (tmp >> dst_depth) + dither[4]) >> shift);
      tmp = (srcPtr2[j + 5]);
      dstPtr2[j + 5] = ((tmp - (tmp >> dst_depth) + dither[5]) >> shift);
      tmp = (srcPtr2[j + 6]);
      dstPtr2[j + 6] = ((tmp - (tmp >> dst_depth) + dither[6]) >> shift);
      tmp = (srcPtr2[j + 7]);
      dstPtr2[j + 7] = ((tmp - (tmp >> dst_depth) + dither[7]) >> shift);
    }
}
