// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_getimage.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;
typedef unsigned int uint32;

int
fn (uint16 k, uint16 g, uint32 w, unsigned char *pp, int samplesperpixel,
    uint32 _x, uint32 * cp, uint16 b, uint16 r)
{
  for (_x = w; _x >= 8; _x -= 8)
    {;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
      k = 255 - pp[3];
      r = (k * (255 - pp[0])) / 255;
      g = (k * (255 - pp[1])) / 255;
      b = (k * (255 - pp[2])) / 255;
      *cp++ =
	((uint32) (r) | ((uint32) (g) << 8) | ((uint32) (b) << 16) |
	 (((uint32) 0xffL) << 24));
      pp += samplesperpixel;
    }
}
