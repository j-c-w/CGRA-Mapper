// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_getimage.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned int uint32;

int
fn (unsigned char *pp, uint32 w, int samplesperpixel, uint32 _x, uint32 * cp)
{
  for (_x = w; _x >= 8; _x -= 8)
    {;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      *cp++ =
	((uint32) (pp[0]) | ((uint32) (pp[1]) << 8) | ((uint32) (pp[2]) << 16)
	 | (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
    }
}
