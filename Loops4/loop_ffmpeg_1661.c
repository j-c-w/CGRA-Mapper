// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavs.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, uint64_t a, uint8_t * left, ptrdiff_t stride, uint8_t * d)
{
  for (y = 0; y < 8; y++)
    {
      a = left[y + 1] * 0x0101010101010101ULL;
      *((uint64_t *) (d + y * stride)) = a;
    }
}
