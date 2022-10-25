// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strenc.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef unsigned char U8;
typedef int PixelI;

int
fn (PixelI * pY, const size_t cShift, const U8 * pSrc, const PixelI iOffset,
    size_t iPos, size_t iColumn, PixelI * pK, const size_t cColumn,
    size_t iRow, PixelI * pV, const size_t cPixelStride,
    const U8 idxCC[16][16], PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cPixelStride)
    {
      PixelI c = ((PixelI) pSrc[0]) << cShift;
      PixelI m = ((PixelI) pSrc[1]) << cShift;
      PixelI y = ((PixelI) pSrc[2]) << cShift;
      PixelI k = ((PixelI) pSrc[3]) << cShift;
      (y -= c, c += ((y + 1) >> 1) - m, m += (c >> 1) - k, k +=
       ((m + 1) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = c, pV[iPos] = -y, pK[iPos] = k, pY[iPos] = iOffset - m;
    }
}
