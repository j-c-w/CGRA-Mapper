// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;
typedef int I32;
typedef unsigned short U16;

int
fn (const I32 iWidth, I32 x, const U16 * piSrcPixel, U32 * piDstPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      const unsigned int r = piSrcPixel[3 * x];
      const unsigned int g = piSrcPixel[3 * x + 1];
      const unsigned int b = piSrcPixel[3 * x + 2];
      piDstPixel[x] =
	(3 << 30) | ((r & 0x0000FFC0) << 14) | ((g & 0x0000FFC0) << 4) | (b >>
									  6);
}}
