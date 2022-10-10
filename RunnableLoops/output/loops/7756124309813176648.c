#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int i, int w, const uint8_t * cursor)
{
  for (i = 0; i < w; i++)
    {
      uint8_t alpha = cursor[i * 4];
      dst[i * 3 + 0] =
	(dst[i * 3 + 0] * (256 - alpha) + cursor[i * 4 + 1] * alpha) >> 8;
      dst[i * 3 + 1] =
	(dst[i * 3 + 1] * (256 - alpha) + cursor[i * 4 + 2] * alpha) >> 8;
      dst[i * 3 + 2] =
	(dst[i * 3 + 2] * (256 - alpha) + cursor[i * 4 + 3] * alpha) >> 8;
    }
}
