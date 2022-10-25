// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strenc.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef unsigned char U8;
typedef int PixelI;

int
fn (const size_t iR, PixelI * pY, const size_t cShift, const size_t iB,
    const U8 * pSrc, const PixelI iOffset, size_t iPos, size_t iColumn,
    const size_t cColumn, size_t iRow, PixelI * pV, const size_t cPixelStride,
    const U8 idxCC[16][16], PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cPixelStride)
    {
      PixelI r = ((PixelI) pSrc[iR]) << cShift, g =
	((PixelI) pSrc[1]) << cShift, b = ((PixelI) pSrc[iB]) << cShift;
      (b -= r, r += ((b + 1) >> 1) - g, g += ((r + 0) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = -r, pV[iPos] = b, pY[iPos] = g - iOffset;
    }
}
