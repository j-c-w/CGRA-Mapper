// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lossless_videodsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (const ptrdiff_t stride, int i, int B, int C, const ptrdiff_t width, int A,
    uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      A = src[i - stride];
      B = src[i - (stride + 1)];
      C = src[i - 1];
      src[i] = (A - B + C + src[i]) & 0xFF;
    }
}
