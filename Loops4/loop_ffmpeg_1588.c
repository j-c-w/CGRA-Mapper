// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int x, int ioff, int dx, const uint8_t * src, uint8_t * tmp_ptr,
    int imx)
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
