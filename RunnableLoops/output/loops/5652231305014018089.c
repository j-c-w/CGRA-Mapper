#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * src1, int i, int srcW, int xInc, int16_t * dst1,
    const uint8_t * src2, int dstWidth, int16_t * dst2)
{
  for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--)
    {
      dst1[i] = src1[srcW - 1] * 128;
      dst2[i] = src2[srcW - 1] * 128;
    }
}
