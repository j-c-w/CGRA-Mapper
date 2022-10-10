#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int xmmod, unsigned int t, unsigned int x, unsigned int mbits,
    unsigned int xm, const uint8_t * mask, unsigned int mmult,
    unsigned int xmshf, unsigned int w, int l2depth)
{
  for (x = 0; x < w; x++)
    {
      t +=
	((mask[xm >> xmshf] >> ((~xm & xmmod) << l2depth)) & mbits) * mmult;
      xm++;
    }
}
