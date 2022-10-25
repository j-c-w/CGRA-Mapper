// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;
typedef unsigned short U16;

int
fn (const I32 iWidth, U8 * piDstPixel, I32 x, const U16 * piSrcPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      const U16 r = piSrcPixel[4 * x];
      const U16 g = piSrcPixel[4 * x + 1];
      const U16 b = piSrcPixel[4 * x + 2];
      const U16 a = piSrcPixel[4 * x + 3];
      piDstPixel[4 * x] = r >> 8;
      piDstPixel[4 * x + 1] = g >> 8;
      piDstPixel[4 * x + 2] = b >> 8;
      piDstPixel[4 * x + 3] = a >> 8;
}}
