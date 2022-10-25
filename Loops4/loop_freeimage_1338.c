// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int k, Int j, PixelI * pOrg)
{
  for (j = 48; j > 0; j -= 16)
    {
      pOrg[k + j + 10] -= pOrg[k + j + 10 - 16];
      pOrg[k + j + 2] -= pOrg[k + j + 2 - 16];
      pOrg[k + j + 9] -= pOrg[k + j + 9 - 16];
    }
}
