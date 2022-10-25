// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef int64_t x86_reg;
typedef __uint8_t uint8_t;

int
fn (int x, int dstStride, int srcStride, x86_reg mmxSize, const uint8_t * src,
    int srcWidth, uint8_t * dst)
{
  for (x = mmxSize - 1; x < srcWidth - 1; x++)
    {
      dst[2 * x + 1] = (3 * src[x + 0] + src[x + srcStride + 1]) >> 2;
      dst[2 * x + dstStride + 2] =
	(src[x + 0] + 3 * src[x + srcStride + 1]) >> 2;
      dst[2 * x + dstStride + 1] = (src[x + 1] + 3 * src[x + srcStride]) >> 2;
      dst[2 * x + 2] = (3 * src[x + 1] + src[x + srcStride]) >> 2;
    }
}
