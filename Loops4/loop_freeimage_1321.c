// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strPredQuantEnc.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef int PixelI;

int
fn (Int j, PixelI * pOrg)
{
  for (j = 16; j <= 48; j += 32)
    {
      pOrg[j + 10] -= pOrg[j + 10 - 16];
      pOrg[j + 2] -= pOrg[j + 2 - 16];
      pOrg[j + 9] -= pOrg[j + 9 - 16];
    }
}
