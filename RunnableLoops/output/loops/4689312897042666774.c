#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t * src1, int i, unsigned int xpos, int xInc, int16_t * dst1,
    const uint8_t * src2, int dstWidth, int16_t * dst2)
{
  for (i = 0; i < dstWidth; i++)
    {
      register unsigned int xx = xpos >> 16;
      register unsigned int xalpha = (xpos & 0xFFFF) >> 9;
      dst1[i] = (src1[xx] * (xalpha ^ 127) + src1[xx + 1] * xalpha);
      dst2[i] = (src2[xx] * (xalpha ^ 127) + src2[xx + 1] * xalpha);
      xpos += xInc;
}}
