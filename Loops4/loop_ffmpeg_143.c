// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int tmp, unsigned int shift, const uint8_t * dither,
    const uint16_t * srcPtr2, uint8_t * dstPtr, int length, int j,
    const int dst_depth)
{
  for (; j < length; j++)
    {
      tmp = (srcPtr2[j]);
      dstPtr[j] = ((tmp - (tmp >> dst_depth) + dither[j & 7]) >> shift);
    }
}
