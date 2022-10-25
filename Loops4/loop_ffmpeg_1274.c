// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (unsigned int tmp, unsigned int shift, uint16_t * dstPtr2,
    const uint8_t * dither, const uint16_t * srcPtr2, int length, int j,
    const int dst_depth)
{
  for (j = 0; j < length - 7; j += 8)
    {
      tmp = ((srcPtr2[j + 0]) + dither[0]) >> shift;
      dstPtr2[j + 0] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 1]) + dither[1]) >> shift;
      dstPtr2[j + 1] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 2]) + dither[2]) >> shift;
      dstPtr2[j + 2] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 3]) + dither[3]) >> shift;
      dstPtr2[j + 3] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 4]) + dither[4]) >> shift;
      dstPtr2[j + 4] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 5]) + dither[5]) >> shift;
      dstPtr2[j + 5] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 6]) + dither[6]) >> shift;
      dstPtr2[j + 6] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 7]) + dither[7]) >> shift;
      dstPtr2[j + 7] = (tmp - (tmp >> dst_depth));
    }
}
