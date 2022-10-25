// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef short I16;
typedef int PixelI;
typedef unsigned char U8;
typedef long unsigned int size_t;

int
fn (const size_t rShiftY, size_t iColumn, I16 * pDst, size_t iRow,
    const size_t cChannel, size_t iChannel, PixelI * pChannel[16],
    const PixelI cMul, const U8 nLen, const U8 idxCC[16][16])
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) +
	   idxCC[iRow][iColumn & 15]] * cMul) >> rShiftY) << nLen;
      pDst[iChannel] =
	((I16) ((p) < (-32768) ? (-32768) : ((32767) < (p) ? (32767) : (p))));
    }
}
