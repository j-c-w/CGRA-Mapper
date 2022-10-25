// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short U16;
typedef int PixelI;
typedef unsigned char U8;
typedef long unsigned int size_t;

int
fn (const size_t rShiftY, size_t iColumn, U16 * pDst, PixelI iOffset,
    size_t iRow, const size_t cChannel, size_t iChannel,
    PixelI * pChannel[16], const PixelI cMul, const U8 nLen,
    const U8 idxCC[16][16])
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	(((pChannel[iChannel & 15]
	   [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 15]] +
	   iOffset) * cMul) >> rShiftY) << nLen;
      pDst[iChannel] =
	((U16) ((p) < (0) ? (0) : ((65535) < (p) ? (65535) : (p))));
    }
}
