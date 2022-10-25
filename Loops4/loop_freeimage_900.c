// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef unsigned int U32;
typedef int PixelI;
typedef unsigned char U8;

int
fn (PixelI iBias, const U8 idxCC[16][16], size_t iColumn, size_t iRow,
    const size_t cChannel, PixelI * pChannel[16], U32 * pDst, const U8 nLen,
    size_t iChannel, size_t iShift)
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf]] +
	  iBias) >> iShift);
      p <<= nLen;
      pDst[iChannel] = (U32) (p);
    }
}
