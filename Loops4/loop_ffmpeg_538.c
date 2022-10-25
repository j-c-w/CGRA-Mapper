// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/qpeldsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, int h, int srcStride, const uint8_t * src,
    const uint8_t * cm, uint8_t * dst)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	cm[(((src[0] + src[1]) * 20 - (src[0] + src[2]) * 6 +
	     (src[1] + src[3]) * 3 - (src[2] + src[4])) + 16) >> 5];
      dst[1] =
	cm[(((src[1] + src[2]) * 20 - (src[0] + src[3]) * 6 +
	     (src[0] + src[4]) * 3 - (src[1] + src[5])) + 16) >> 5];
      dst[2] =
	cm[(((src[2] + src[3]) * 20 - (src[1] + src[4]) * 6 +
	     (src[0] + src[5]) * 3 - (src[0] + src[6])) + 16) >> 5];
      dst[3] =
	cm[(((src[3] + src[4]) * 20 - (src[2] + src[5]) * 6 +
	     (src[1] + src[6]) * 3 - (src[0] + src[7])) + 16) >> 5];
      dst[4] =
	cm[(((src[4] + src[5]) * 20 - (src[3] + src[6]) * 6 +
	     (src[2] + src[7]) * 3 - (src[1] + src[8])) + 16) >> 5];
      dst[5] =
	cm[(((src[5] + src[6]) * 20 - (src[4] + src[7]) * 6 +
	     (src[3] + src[8]) * 3 - (src[2] + src[8])) + 16) >> 5];
      dst[6] =
	cm[(((src[6] + src[7]) * 20 - (src[5] + src[8]) * 6 +
	     (src[4] + src[8]) * 3 - (src[3] + src[7])) + 16) >> 5];
      dst[7] =
	cm[(((src[7] + src[8]) * 20 - (src[6] + src[8]) * 6 +
	     (src[5] + src[7]) * 3 - (src[4] + src[6])) + 16) >> 5];
      dst += dstStride;
      src += srcStride;
    }
}
