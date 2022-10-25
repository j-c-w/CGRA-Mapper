// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int j, PixelI * pOrg)
{
  for (j = 64; j <= 112; j += 16)
    {
      pOrg[j + 5] -= pOrg[j + 5 - 64];
      pOrg[j + 1] -= pOrg[j + 1 - 64];
      pOrg[j + 6] -= pOrg[j + 6 - 64];
    }
}
