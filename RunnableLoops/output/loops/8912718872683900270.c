#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * out, const uint8_t * in, int w)
{
  for (int j = 0; j < w; j++, out += 3, in -= 3)
    {
      int32_t v =
	((((const uint8_t *) (in))[0] << 16) |
	 (((const uint8_t *) (in))[1] << 8) | ((const uint8_t *) (in))[2]);
      do
	{
	  ((uint8_t *) (out))[2] = (v);
	  ((uint8_t *) (out))[1] = (v) >> 8;
	  ((uint8_t *) (out))[0] = (v) >> 16;
	}
      while (0);
    }
}
