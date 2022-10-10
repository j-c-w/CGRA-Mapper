#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * cm, int srcStride, int i, uint8_t * dst,
    const uint8_t * src)
{
  const int w = 8;
  for (i = 0; i < w; i++)
    {
      dst[i] =
	(((dst[i]) +
	  cm[(36 * src[i + srcStride * 0] + 54 * src[i + 1 + srcStride * 0] +
	      6 * src[i + 2 + srcStride * 0] + 54 * src[i + srcStride * 1] +
	      81 * src[i + 1 + srcStride * 1] + 9 * src[i + 2 +
							srcStride * 1] +
	      6 * src[i + srcStride * 2] + 9 * src[i + 1 + srcStride * 2] +
	      src[i + 2 + srcStride * 2] + 128) >> 8] + 1) >> 1);
    }
}
