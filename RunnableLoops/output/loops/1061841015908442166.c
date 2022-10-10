#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * tmp, int srcStride, int tmpStride, int i, const int pad,
    const uint8_t * src)
{
  const int h = 4;
  for (i = 0; i < h + 5; i++)
    {
      tmp[0] =
	(src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) +
	pad;
      tmp[1] =
	(src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) +
	pad;
      tmp[2] =
	(src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) +
	pad;
      tmp[3] =
	(src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) +
	pad;
      tmp += tmpStride;
      src += srcStride;
    }
}
