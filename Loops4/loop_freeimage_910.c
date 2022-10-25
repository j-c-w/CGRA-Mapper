// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/strenc.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef short I16;
typedef int PixelI;
typedef unsigned char U8;

int
fn (PixelI * pY, const size_t cShift, const I16 * pSrc, size_t iPos,
    size_t iColumn, PixelI * pK, const size_t cColumn, size_t iRow,
    PixelI * pV, const size_t cStride, const U8 nLen, const U8 idxCC[16][16],
    PixelI * pU)
{
  for (iColumn = 0; iColumn < cColumn; iColumn++, pSrc += cStride)
    {
      PixelI c = ((PixelI) pSrc[0] >> nLen) << cShift;
      PixelI m = ((PixelI) pSrc[1] >> nLen) << cShift;
      PixelI y = ((PixelI) pSrc[2] >> nLen) << cShift;
      PixelI k = ((PixelI) pSrc[3] >> nLen) << cShift;
      (y -= c, c += ((y + 1) >> 1) - m, m += (c >> 1) - k, k +=
       ((m + 1) >> 1));
      iPos = ((iColumn >> 4) << 8) + idxCC[iRow][iColumn & 0xf];
      pU[iPos] = c, pV[iPos] = -y, pK[iPos] = k, pY[iPos] = -m;
    }
}
