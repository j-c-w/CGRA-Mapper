// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideodsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int rounder, int h, const int D, const int A, const int B,
    const int C, uint8_t * dst, uint8_t * src, int stride)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	(A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] +
	 rounder) >> 8;
      dst[1] =
	(A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] +
	 rounder) >> 8;
      dst[2] =
	(A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] +
	 rounder) >> 8;
      dst[3] =
	(A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] +
	 rounder) >> 8;
      dst[4] =
	(A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5] +
	 rounder) >> 8;
      dst[5] =
	(A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6] +
	 rounder) >> 8;
      dst[6] =
	(A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7] +
	 rounder) >> 8;
      dst[7] =
	(A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8] +
	 rounder) >> 8;
      dst += stride;
      src += stride;
    }
}
