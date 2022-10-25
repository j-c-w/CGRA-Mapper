// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vc1dsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int i, ptrdiff_t stride, int h, const int D, const int A, const int B,
    const int C, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	((A * src[0] + B * src[0 + 1] + C * src[stride + 0] +
	  D * src[stride + 0 + 1] + 32 - 4) >> 6);
      dst[1] =
	((A * src[1] + B * src[1 + 1] + C * src[stride + 1] +
	  D * src[stride + 1 + 1] + 32 - 4) >> 6);
      dst[2] =
	((A * src[2] + B * src[2 + 1] + C * src[stride + 2] +
	  D * src[stride + 2 + 1] + 32 - 4) >> 6);
      dst[3] =
	((A * src[3] + B * src[3 + 1] + C * src[stride + 3] +
	  D * src[stride + 3 + 1] + 32 - 4) >> 6);
      dst[4] =
	((A * src[4] + B * src[4 + 1] + C * src[stride + 4] +
	  D * src[stride + 4 + 1] + 32 - 4) >> 6);
      dst[5] =
	((A * src[5] + B * src[5 + 1] + C * src[stride + 5] +
	  D * src[stride + 5 + 1] + 32 - 4) >> 6);
      dst[6] =
	((A * src[6] + B * src[6 + 1] + C * src[stride + 6] +
	  D * src[stride + 6 + 1] + 32 - 4) >> 6);
      dst[7] =
	((A * src[7] + B * src[7 + 1] + C * src[stride + 7] +
	  D * src[stride + 7 + 1] + 32 - 4) >> 6);
      dst += stride;
      src += stride;
    }
}
