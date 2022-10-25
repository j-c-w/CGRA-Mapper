// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int I32;

int
fn (I32 * pDC, PixelI * pData, int i, const int dctIndex[3][16])
{
  for (i = 0; i < 16; i++)
    {
      pDC[i] = pData[dctIndex[2][i]];
    }
}
