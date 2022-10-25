// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char U8;
typedef long unsigned int size_t;
typedef int PixelI;

int
fn (U8 * pDst, PixelI iBias, size_t iColumn, size_t iRow,
    const size_t cChannel, size_t iChannel, PixelI * pChannel[16],
    const U8 idxCC[16][16], size_t iShift)
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 15]] +
	  iBias) >> iShift);
      pDst[iChannel] = ((U8) ((p) < (0) ? (0) : ((255) < (p) ? (255) : (p))));
    }
}
