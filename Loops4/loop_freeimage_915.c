// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strenc.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef int I32;
typedef unsigned char U8;
typedef int PixelI;

int
fn (PixelI * pY, const size_t cShift, size_t iPos, size_t iColumn,
    const size_t cColumn, size_t iRow, const I32 * pSrc, PixelI * pV,
    const size_t cStride, const U8 nLen, const U8 idxCC[16][16], PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cStride)
    {
      PixelI r = (pSrc[0] >> nLen) << cShift, g =
	(pSrc[1] >> nLen) << cShift, b = (pSrc[2] >> nLen) << cShift;
      (b -= r, r += ((b + 1) >> 1) - g, g += ((r + 0) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = -r, pV[iPos] = b, pY[iPos] = g;
    }
}
