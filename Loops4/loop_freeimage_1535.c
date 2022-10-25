// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef short I16;

int
fn (I32 x, const I32 iWidth, const float *pfltSrcPixel,
    const float fltCvtFactor, I16 * piDstPixel)
{
  for (x = 0; x < iWidth; x++)
    {
      piDstPixel[4 * x] = (I16) (pfltSrcPixel[3 * x] * fltCvtFactor + 0.5F);
      piDstPixel[4 * x + 1] =
	(I16) (pfltSrcPixel[3 * x + 1] * fltCvtFactor + 0.5F);
      piDstPixel[4 * x + 2] =
	(I16) (pfltSrcPixel[3 * x + 2] * fltCvtFactor + 0.5F);
      piDstPixel[4 * x + 3] = 0;
    }
}
