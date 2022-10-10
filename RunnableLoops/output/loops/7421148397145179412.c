#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, int imx, int dx, uint16_t * tmp_ptr, int ioff,
    const uint16_t * src, int w)
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
