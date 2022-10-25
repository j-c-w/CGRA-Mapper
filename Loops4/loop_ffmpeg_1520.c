// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snow.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, const unsigned int color, ptrdiff_t stride, int x, int b_w,
    uint8_t * dst)
{
  for (x = 0; x < b_w; x++)
    {
      dst[x + y * stride] = color;
    }
}
