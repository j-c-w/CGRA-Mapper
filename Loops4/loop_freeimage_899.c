// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef long unsigned int size_t;
typedef int PixelI;
typedef unsigned char U8;

int
fn (I32 * pDst, PixelI iBias, size_t iColumn, size_t iRow,
    const size_t cChannel, size_t iChannel, PixelI * pChannel[16],
    const U8 nLen, const U8 idxCC[16][16], size_t iShift)
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf]] +
	  iBias) >> iShift);
      p <<= nLen;
      pDst[iChannel] = (I32) (p);
    }
}
