// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_swab.c

#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned char uint8;

int
fn (uint8 * cp, const unsigned char TIFFBitRevTable[256], tmsize_t n)
{
  for (; n > 8; n -= 8)
    {
      cp[0] = TIFFBitRevTable[cp[0]];
      cp[1] = TIFFBitRevTable[cp[1]];
      cp[2] = TIFFBitRevTable[cp[2]];
      cp[3] = TIFFBitRevTable[cp[3]];
      cp[4] = TIFFBitRevTable[cp[4]];
      cp[5] = TIFFBitRevTable[cp[5]];
      cp[6] = TIFFBitRevTable[cp[6]];
      cp[7] = TIFFBitRevTable[cp[7]];
      cp += 8;
    }
}
