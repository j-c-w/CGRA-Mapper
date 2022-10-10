#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int32_t gu, int16_t * dstU, int i, const uint8_t * src1, int16_t * dstV,
    int32_t rv, int width, int32_t bu, int32_t gv, int32_t bv, int32_t ru)
{
  for (i = 0; i < width; i++)
    {
      int r = src1[6 * i + 0] + src1[6 * i + 3];
      int g = src1[6 * i + 1] + src1[6 * i + 4];
      int b = src1[6 * i + 2] + src1[6 * i + 5];
      dstU[i] =
	(ru * r + gu * g + bu * b + (256 << 15) + (1 << (15 - 6))) >> (15 -
								       5);
      dstV[i] =
	(rv * r + gv * g + bv * b + (256 << 15) + (1 << (15 - 6))) >> (15 -
								       5);
}}
