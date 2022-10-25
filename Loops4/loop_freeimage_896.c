// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef unsigned char U8;
typedef unsigned int U32;
typedef long unsigned int size_t;

int
fn (const size_t rShiftY, const U8 idxCC[16][16], size_t iColumn,
    PixelI iOffset, size_t iRow, const size_t cChannel, U32 * pDst,
    PixelI * pChannel[16], const PixelI cMul, const U8 nLen, size_t iChannel)
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	(((pChannel[iChannel & 15]
	   [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 15]] +
	   iOffset) * cMul) >> rShiftY) << nLen;
      pDst[iChannel] = (U32) (p);
    }
}
