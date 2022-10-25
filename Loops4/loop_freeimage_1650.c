// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_getimage.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (uint32 ** BWmap, unsigned char *pp, uint32 w, int samplesperpixel,
    uint32 * cp, uint32 x)
{
  for (x = w; x > 0; --x)
    {
      *cp++ =
	BWmap[*pp][0] & ((uint32) *
			 (pp + 1) << 24 | ~(((uint32) 0xffL) << 24));
      pp += samplesperpixel;
    }
}
