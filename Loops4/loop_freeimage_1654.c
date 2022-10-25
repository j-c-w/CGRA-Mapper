// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_getimage.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned char TIFFRGBValue;

int
fn (uint16 k, uint16 g, uint32 w, unsigned char *pp, int samplesperpixel,
    uint32 * cp, TIFFRGBValue * Map, uint16 b, uint16 r, uint32 x)
{
  for (x = w; x > 0; --x)
    {
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (Map[r]) | ((uint32) (Map[g]) << 8) |
	 ((uint32) (Map[b]) << 16) | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
    }
}
