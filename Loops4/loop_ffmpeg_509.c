// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/hpeldsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int a1, int b1, int i, int a0, uint8_t * block, int h,
    ptrdiff_t line_size, const uint8_t * pixels, int b0)
{
  for (i = 0; i < h; i += 2)
    {
      a1 = pixels[0];
      b1 = pixels[1];
      a1 += b1;
      b1 += pixels[2];
      block[0] = (a1 + a0) >> 2;
      block[1] = (b1 + b0) >> 2;
      pixels += line_size;
      block += line_size;
      a0 = pixels[0];
      b0 = pixels[1] + 2;
      a0 += b0;
      b0 += pixels[2];
      block[0] = (a1 + a0) >> 2;
      block[1] = (b1 + b0) >> 2;
      pixels += line_size;
      block += line_size;
    }
}
