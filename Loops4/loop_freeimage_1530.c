// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned short U16;
typedef unsigned char U8;

int
fn (const I32 iWidth, U16 * piDstPixel, const U8 * piSrcPixel, I32 x)
{
  for (x = 0; x < iWidth; x++)
    {
      const unsigned int r = piSrcPixel[3 * x];
      const unsigned int g = piSrcPixel[3 * x + 1];
      const unsigned int b = piSrcPixel[3 * x + 2];
      piDstPixel[x] =
	(U16) (((r & 0xF8) << 7) | ((g & 0xF8) << 2) | (b >> 3));
}}
