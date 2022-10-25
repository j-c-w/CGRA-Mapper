// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;
typedef unsigned short U16;

int
fn (const I32 iWidth, U8 * piDstPixel, I32 x, const U16 * piSrcPixel)
{
  for (x = iWidth - 1; x >= 0; x--)
    {
      const U16 v = piSrcPixel[x];
      const unsigned int r = ((v >> 10) & 0x1f);
      const unsigned int g = ((v >> 5) & 0x1f);
      const unsigned int b = (v & 0x1f);
      piDstPixel[3 * x] = (U8) (r << 3);
      piDstPixel[3 * x + 1] = (U8) (g << 3);
      piDstPixel[3 * x + 2] = (U8) (b << 3);
}}
