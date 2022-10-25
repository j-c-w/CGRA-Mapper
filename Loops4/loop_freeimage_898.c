// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;
typedef unsigned char U8;
typedef long unsigned int size_t;
typedef int I32;

int
fn (const size_t rShiftY, const U8 idxCC[16][16], size_t iColumn, size_t iRow,
    const size_t cChannel, PixelI * pChannel[16], const PixelI cMul,
    const U8 nLen, size_t iChannel, I32 * pDst)
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) +
	   idxCC[iRow][iColumn & 15]] * cMul) >> rShiftY) << nLen;
      pDst[iChannel] = (I32) (p);
    }
}
