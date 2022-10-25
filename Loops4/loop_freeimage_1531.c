// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;
typedef unsigned short U16;

int
fn (const I32 iWidth, U16 * piDstPixel, I32 x, const U8 * piSrcPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      const unsigned int r = piSrcPixel[3 * x];
      const unsigned int g = piSrcPixel[3 * x + 1];
      const unsigned int b = piSrcPixel[3 * x + 2];
      piDstPixel[x] =
	(U16) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3));
}}
