#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, const uint8_t * asrc, uint8_t * dst, const uint8_t * msrc, int w)
{
  for (x = 0; x < w; x++)
    {
      dst[x] =
	((((msrc[x] - 128) * (((asrc[x] >> 1) & 1) + asrc[x]))) >> 8) + 128;
    }
}
