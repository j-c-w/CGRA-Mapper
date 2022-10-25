// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strenc.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef int PixelI;
typedef unsigned char U8;

int
fn (PixelI * pY, const size_t cShift, const U8 * pSrc, const PixelI iOffset,
    size_t iPos, size_t iColumn, const size_t cColumn, size_t iRow,
    PixelI * pV, const size_t cPixelStride, const U8 idxCC[16][16],
    PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cPixelStride)
    {
      PixelI r = (PixelI) pSrc[0], g = (PixelI) pSrc[1], b = (PixelI) pSrc[2];
      r = (r + ((g & 3) << 8)) << cShift, g =
	((g >> 2) + ((b & 0xF) << 6)) << cShift;
      b = ((b >> 4) + (((PixelI) pSrc[3] & 0x3F) << 4)) << cShift;
      (b -= r, r += ((b + 1) >> 1) - g, g += ((r + 0) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = -r, pV[iPos] = b, pY[iPos] = g - iOffset;
    }
}
