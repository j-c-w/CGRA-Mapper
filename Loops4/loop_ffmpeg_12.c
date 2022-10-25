// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, const uint8_t * src, ptrdiff_t dstStride, ptrdiff_t srcStride,
    const uint8_t * cm, uint8_t * dst)
{
  const int h = 8;
  for (i = 0; i < h; i++)
    {
      dst[0] =
	((dst[0]) +
	 cm[((-1 * src[-2] + -2 * src[-1] + 96 * src[0] + 42 * src[1] +
	      -7 * src[2] + 0 * src[3]) + 64) >> 7] + 1) >> 1;
      dst[1] =
	((dst[1]) +
	 cm[((-1 * src[-1] + -2 * src[0] + 96 * src[1] + 42 * src[2] +
	      -7 * src[3] + 0 * src[4]) + 64) >> 7] + 1) >> 1;
      dst[2] =
	((dst[2]) +
	 cm[((-1 * src[0] + -2 * src[1] + 96 * src[2] + 42 * src[3] +
	      -7 * src[4] + 0 * src[5]) + 64) >> 7] + 1) >> 1;
      dst[3] =
	((dst[3]) +
	 cm[((-1 * src[1] + -2 * src[2] + 96 * src[3] + 42 * src[4] +
	      -7 * src[5] + 0 * src[6]) + 64) >> 7] + 1) >> 1;
      dst[4] =
	((dst[4]) +
	 cm[((-1 * src[2] + -2 * src[3] + 96 * src[4] + 42 * src[5] +
	      -7 * src[6] + 0 * src[7]) + 64) >> 7] + 1) >> 1;
      dst[5] =
	((dst[5]) +
	 cm[((-1 * src[3] + -2 * src[4] + 96 * src[5] + 42 * src[6] +
	      -7 * src[7] + 0 * src[8]) + 64) >> 7] + 1) >> 1;
      dst[6] =
	((dst[6]) +
	 cm[((-1 * src[4] + -2 * src[5] + 96 * src[6] + 42 * src[7] +
	      -7 * src[8] + 0 * src[9]) + 64) >> 7] + 1) >> 1;
      dst[7] =
	((dst[7]) +
	 cm[((-1 * src[5] + -2 * src[6] + 96 * src[7] + 42 * src[8] +
	      -7 * src[9] + 0 * src[10]) + 64) >> 7] + 1) >> 1;
      dst += dstStride;
      src += srcStride;
    }
}
