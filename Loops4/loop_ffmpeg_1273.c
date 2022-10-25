// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int shift, const uint16_t * srcPtr2, uint8_t * dstPtr,
    int length, int j)
{
  for (j = 0; j < length - 7; j += 8)
    {
      dstPtr[j + 0] = ((srcPtr2[j + 0]) >> shift);
      dstPtr[j + 1] = ((srcPtr2[j + 1]) >> shift);
      dstPtr[j + 2] = ((srcPtr2[j + 2]) >> shift);
      dstPtr[j + 3] = ((srcPtr2[j + 3]) >> shift);
      dstPtr[j + 4] = ((srcPtr2[j + 4]) >> shift);
      dstPtr[j + 5] = ((srcPtr2[j + 5]) >> shift);
      dstPtr[j + 6] = ((srcPtr2[j + 6]) >> shift);
      dstPtr[j + 7] = ((srcPtr2[j + 7]) >> shift);
    }
}
