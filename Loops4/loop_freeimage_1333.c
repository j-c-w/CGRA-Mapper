// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strPredQuantDec.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef int Int;

int
fn (PixelI * pOrg, PixelI * pSrc, Int j, PixelI * pRef)
{
  for (j = 1; j <= 3; j += 2)
    {
      pOrg = pSrc + 16 * j;
      pRef = pOrg - 16;
      pOrg[2] += pRef[2];
      pOrg[10] += pRef[10];
      pOrg[9] += pRef[9];
    }
}
