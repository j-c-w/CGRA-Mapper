#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int32_t gu, int i, const uint8_t * bsrc, const uint8_t * rsrc, int32_t rv,
    int width, int32_t bu, uint16_t * dstU, const uint8_t * gsrc, int32_t gv,
    int32_t bv, uint16_t * dstV, int32_t ru)
{
  for (i = 0; i < width; i++)
    {
      unsigned int g = gsrc[2 * i] + gsrc[2 * i + 1];
      unsigned int b = bsrc[2 * i] + bsrc[2 * i + 1];
      unsigned int r = rsrc[2 * i] + rsrc[2 * i + 1];
      dstU[i] =
	(ru * r + gu * g + bu * b + (0x4001 << (15 - 6))) >> (15 - 6 + 1);
      dstV[i] =
	(rv * r + gv * g + bv * b + (0x4001 << (15 - 6))) >> (15 - 6 + 1);
}}
