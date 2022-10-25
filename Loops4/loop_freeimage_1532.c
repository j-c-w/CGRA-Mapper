// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;

int
fn (const I32 iWidth, const float *pfltSrcPixel, I32 x, float *pfltDstPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      pfltDstPixel[3 * x] = pfltSrcPixel[4 * x];
      pfltDstPixel[3 * x + 1] = pfltSrcPixel[4 * x + 1];
      pfltDstPixel[3 * x + 2] = pfltSrcPixel[4 * x + 2];
    }
}
