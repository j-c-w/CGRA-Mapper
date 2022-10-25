// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv30dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int srcStride, const uint8_t * src, const uint8_t * cm,
    uint8_t * dst)
{
  const int w = 8;
  for (i = 0; i < w; i++)
    {
      dst[i] =
	(((dst[i]) +
	  cm[(src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i] -
	      6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 2] +
	      -6 * src[srcStride * 0 + i - 1] + 72 * src[srcStride * 0 + i] +
	      36 * src[srcStride * 0 + i + 1] - 6 * src[srcStride * 0 + i +
							2] +
	      -12 * src[srcStride * 1 + i - 1] + 144 * src[srcStride * 1 +
							   i] +
	      72 * src[srcStride * 1 + i + 1] - 12 * src[srcStride * 1 + i +
							 2] +
	      src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i] -
	      6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 2] +
	      128) >> 8] + 1) >> 1);
    }
}
