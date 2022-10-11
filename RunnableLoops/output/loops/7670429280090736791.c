#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int imx, uint8_t * tmp_ptr, int dx, int ioff, int w,
    const uint8_t * src)
{
  for (x = 0; x < w; x++)
    {
      tmp_ptr[x] =
	(src[ioff] + ((imx * (src[ioff + 1] - src[ioff]) + 8) >> 4));
      imx += dx;
      ioff += imx >> 4;
      imx &= 0xf;
    }
}