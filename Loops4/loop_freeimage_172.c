// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_getimage.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (unsigned char *pp, uint32 w, uint32 * cp, uint32 _x, uint32 ** PALmap,
    uint32 * bw)
{
  for (_x = w; _x >= 8; _x -= 8)
    {
      bw = PALmap[*pp++];
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
      *cp++ = *bw++;
    }
}
