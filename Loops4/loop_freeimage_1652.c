// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_getimage.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;
typedef unsigned int uint32;

int
fn (uint32 ** BWmap, uint32 w, unsigned char *pp, int samplesperpixel,
    uint32 * cp, uint16 * wp, uint32 x)
{
  for (x = w; x > 0; --x)
    {
      *cp++ = BWmap[*wp >> 8][0];
      pp += 2 * samplesperpixel;
      wp += samplesperpixel;
    }
}
