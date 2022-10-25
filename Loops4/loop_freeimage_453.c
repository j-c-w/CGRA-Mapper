// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int I32;

int
fn (I32 * pDC, const int blkOffsetUV_422[8], int i, PixelI * pData)
{
  for (i = 0; i < 8; i++)
    {
      pDC[i] = pData[blkOffsetUV_422[i]];
    }
}
