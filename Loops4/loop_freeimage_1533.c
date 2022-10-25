// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;

int
fn (I32 x, const I32 iWidth, const I32 * piSrcPixel, float *pfltDstPixel,
    const float fltCvtFactor)
{
  for (x = 0; x < iWidth; x++)
    {
      pfltDstPixel[3 * x] = piSrcPixel[4 * x] * fltCvtFactor;
      pfltDstPixel[3 * x + 1] = piSrcPixel[4 * x + 1] * fltCvtFactor;
      pfltDstPixel[3 * x + 2] = piSrcPixel[4 * x + 2] * fltCvtFactor;
    }
}
