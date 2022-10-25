// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef int I32;

int
fn (U8 * piPixel, const I32 iWidthX4, I32 x)
{
  for (x = 0; x < iWidthX4; x += 4)
    {
      U8 bTemp = piPixel[x];
      piPixel[x] = piPixel[x + 2];
      piPixel[x + 2] = bTemp;
    }
}
