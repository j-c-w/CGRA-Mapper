#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef int64_t x86_reg;

int
fn (int dstStride, int srcStride, int x, uint8_t * dst, x86_reg mmxSize,
    int srcWidth, const uint8_t * src)
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
