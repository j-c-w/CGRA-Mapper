#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int components, int step, uint8_t * dst, int w, const uint8_t * src)
{
  for (int x = 0; x < w; x++)
    {
      switch (step)
	{
	case 4:
	  dst[3] = components & 8 ? 255 - src[3] : src[3];
	case 3:
	  dst[2] = components & 4 ? 255 - src[2] : src[2];
	case 2:
	  dst[1] = components & 2 ? 255 - src[1] : src[1];
	default:
	  dst[0] = components & 1 ? 255 - src[0] : src[0];
	}
      src += step;
      dst += step;
    }
}
