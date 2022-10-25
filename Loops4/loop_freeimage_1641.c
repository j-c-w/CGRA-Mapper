// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;

int
fn (const I32 iWidth, U8 * piDstPixel, const U8 * piSrcPixel, I32 x)
{
  for (x = iWidth - 1; x >= 0; x--)
    {
      piDstPixel[4 * x] = piSrcPixel[3 * x];
      piDstPixel[4 * x + 1] = piSrcPixel[3 * x + 1];
      piDstPixel[4 * x + 2] = piSrcPixel[3 * x + 2];
      piDstPixel[4 * x + 3] = 0;
    }
}
