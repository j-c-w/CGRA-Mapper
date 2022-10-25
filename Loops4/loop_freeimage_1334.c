// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strPredQuantDec.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (PixelI * pSrc, Int j, const int blkOffsetUV_422[8], PixelI * pOrg,
    PixelI * pRef)
{
  for (j = 2; j < 8; j++)
    {
      pOrg = pSrc + blkOffsetUV_422[j];
      pRef = pOrg - 16;
      pOrg[10] += pRef[10];
      pOrg[2] += pRef[2];
      pOrg[9] += pRef[9];
    }
}
