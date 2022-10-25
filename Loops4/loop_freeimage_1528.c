// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;
typedef int I32;
typedef unsigned char U8;

int
fn (const I32 iWidth, U8 * piDstPixel, I32 x, const U32 * piSrcPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      const U32 v = piSrcPixel[x];
      const unsigned int r = ((v >> 20) & 0x3FF);
      const unsigned int g = ((v >> 10) & 0x3FF);
      const unsigned int b = (v & 0x3FF);
      piDstPixel[3 * x] = (U8) (r >> 2);
      piDstPixel[3 * x + 1] = (U8) (g >> 2);
      piDstPixel[3 * x + 2] = (U8) (b >> 2);
}}
