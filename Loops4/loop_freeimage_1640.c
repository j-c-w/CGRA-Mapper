// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;

int
fn (I32 x, const I32 iWidth, const float *pfltSrcPixel, I32 * piDstPixel,
    const float fltCvtFactor)
{
  for (x = iWidth - 1; x >= 0; x--)
    {
      piDstPixel[4 * x] = (I32) (pfltSrcPixel[3 * x] * fltCvtFactor + 0.5F);
      piDstPixel[4 * x + 1] =
	(I32) (pfltSrcPixel[3 * x + 1] * fltCvtFactor + 0.5F);
      piDstPixel[4 * x + 2] =
	(I32) (pfltSrcPixel[3 * x + 2] * fltCvtFactor + 0.5F);
      piDstPixel[4 * x + 3] = 0;
    }
}
