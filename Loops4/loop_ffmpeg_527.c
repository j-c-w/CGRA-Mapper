// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264chroma.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int A,
    uint16_t * dst, const int E, const int step)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	(((dst[0]) + ((((A * src[0] + E * src[step + 0])) + 32) >> 6) +
	  1) >> 1);
      dst += stride;
      src += stride;
    }
}
