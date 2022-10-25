// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int32_t gv, int i, int32_t bu, const uint8_t * gsrc, int width,
    int32_t ru, int32_t bv, uint16_t * dstU, int32_t rv, uint16_t * dstV,
    const uint8_t * rsrc, const uint8_t * bsrc, int32_t gu)
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
