// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int I32;

int
fn (I32 * pDC, int i, PixelI * pData, const int blkOffsetUV[4])
{
  for (i = 0; i < 4; i++)
    {
      pDC[i] = pData[blkOffsetUV[i]];
    }
}
