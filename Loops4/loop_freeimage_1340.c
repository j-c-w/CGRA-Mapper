// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strPredQuantDec.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int Int;

int
fn (PixelI * pOrg, Int j, PixelI * pSrc, PixelI * pRef)
{
  for (j = 64; j < 256; j += 16)
    {
      pOrg = pSrc + j;
      pRef = pOrg - 64;
      pOrg[1] += pRef[1];
      pOrg[5] += pRef[5];
      pOrg[6] += pRef[6];
    }
}
