// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv40dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const int h, int srcStride, const uint8_t * src,
    const int SHIFT, const int C2, const uint8_t * cm, const int C1,
    uint8_t * dst)
{
  for (i = 0; i < h; i++)
    {
      dst[0] =
	cm[(src[-2] + src[3] - 5 * (src[-1] + src[2]) + src[0] * C1 +
	    src[1] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[1] =
	cm[(src[-1] + src[4] - 5 * (src[0] + src[3]) + src[1] * C1 +
	    src[2] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[2] =
	cm[(src[0] + src[5] - 5 * (src[1] + src[4]) + src[2] * C1 +
	    src[3] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[3] =
	cm[(src[1] + src[6] - 5 * (src[2] + src[5]) + src[3] * C1 +
	    src[4] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[4] =
	cm[(src[2] + src[7] - 5 * (src[3] + src[6]) + src[4] * C1 +
	    src[5] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[5] =
	cm[(src[3] + src[8] - 5 * (src[4] + src[7]) + src[5] * C1 +
	    src[6] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[6] =
	cm[(src[4] + src[9] - 5 * (src[5] + src[8]) + src[6] * C1 +
	    src[7] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst[7] =
	cm[(src[5] + src[10] - 5 * (src[6] + src[9]) + src[7] * C1 +
	    src[8] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
      dst += dstStride;
      src += srcStride;
    }
}
