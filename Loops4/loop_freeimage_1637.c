// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned int U32;
typedef unsigned short U16;

int
fn (const I32 iWidth, I32 x, U16 * piDstPixel, const U32 * piSrcPixel)
{
  for (x = iWidth - 1; x >= 0; x--)
    {
      const U32 v = piSrcPixel[x];
      const unsigned int r = ((v >> 20) & 0x3FF);
      const unsigned int g = ((v >> 10) & 0x3FF);
      const unsigned int b = (v & 0x3FF);
      piDstPixel[3 * x] = (U16) (r << 6);
      piDstPixel[3 * x + 1] = (U16) (g << 6);
      piDstPixel[3 * x + 2] = (U16) (b << 6);
}}
