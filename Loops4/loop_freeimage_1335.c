// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strPredQuantDec.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int Int;

int
fn (PixelI * pOrg, PixelI * pSrc, Int j, PixelI * pRef)
{
  for (j = 2; j <= 3; ++j)
    {
      pOrg = pSrc + 16 * j;
      pRef = pOrg - 32;
      pOrg[1] += pRef[1];
      pOrg[5] += pRef[5];
      pOrg[6] += pRef[6];
    }
}
