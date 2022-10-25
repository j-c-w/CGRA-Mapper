// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;

int
fn (float *pfltDstPixel, const float *pfltSrcPixel, I32 x, const I32 iWidth)
{
  for (x = iWidth - 1; x >= 0; x--)
    {
      pfltDstPixel[4 * x] = pfltSrcPixel[3 * x];
      pfltDstPixel[4 * x + 1] = pfltSrcPixel[3 * x + 1];
      pfltDstPixel[4 * x + 2] = pfltSrcPixel[3 * x + 2];
      pfltDstPixel[4 * x + 3] = 0.0F;
    }
}
