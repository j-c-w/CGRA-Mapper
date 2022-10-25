// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/texturedspenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * block, int y, int g, ptrdiff_t stride, int x, int r)
{
  int b = 8;
  for (x = 0; x < 4; x++)
    {
      r += block[0 + x * 4 + y * stride];
      g += block[1 + x * 4 + y * stride];
      b += block[2 + x * 4 + y * stride];
    }
}
