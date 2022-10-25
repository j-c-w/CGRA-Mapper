// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/magicyuvenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, int top, ptrdiff_t stride, int width, const uint8_t * src,
    uint8_t * dst, int left)
{
  int lefttop = 0;
  for (i = 1; i < width; i++)
    {
      top = src[i - stride];
      lefttop = src[i - (stride + 1)];
      left = src[i - 1];
      dst[i] = (src[i] - top) - left + lefttop;
    }
}
