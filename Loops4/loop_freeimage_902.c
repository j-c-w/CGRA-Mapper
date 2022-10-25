// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strdec.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef int PixelI;
typedef unsigned char U8;
typedef unsigned short U16;

int
fn (PixelI iBias, const U8 idxCC[16][16], size_t iColumn, U16 * pDst,
    size_t iRow, const size_t cChannel, PixelI * pChannel[16], const U8 nLen,
    size_t iChannel, size_t iShift)
{
  for (iChannel = 0; iChannel < cChannel; iChannel++)
    {
      PixelI p =
	((pChannel[iChannel & 15]
	  [((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 15]] +
	  iBias) >> iShift);
      p <<= nLen;
      pDst[iChannel] =
	((U16) ((p) < (0) ? (0) : ((65535) < (p) ? (65535) : (p))));
    }
}
