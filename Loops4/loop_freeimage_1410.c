// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int k, Int j, PixelI * pOrg)
{
  for (k = 0; k <= 64; k += 64)
    {
      pOrg[j + k + 10] -= pOrg[j + k + 10 - 16];
      pOrg[j + k + 2] -= pOrg[j + k + 2 - 16];
      pOrg[j + k + 9] -= pOrg[j + k + 9 - 16];
    }
}
