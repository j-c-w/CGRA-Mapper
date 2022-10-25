// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strPredQuantDec.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (PixelI * pSrc, Int j, const int blkOffsetUV_422[8], PixelI * pOrg,
    PixelI * pRef)
{
  for (j = 1; j < 8; j += 2)
    {
      pOrg = pSrc + blkOffsetUV_422[j];
      pRef = pOrg - 64;
      pOrg[1] += pRef[1];
      pOrg[5] += pRef[5];
      pOrg[6] += pRef[6];
    }
}
