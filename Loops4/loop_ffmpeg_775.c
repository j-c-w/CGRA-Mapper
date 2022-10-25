// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * dstV, int32_t gv, int i, int32_t bu, int width, int32_t ru,
    int32_t bv, int32_t rv, int16_t * dstU, const uint8_t * src1, int32_t gu)
{
  for (i = 0; i < width; i++)
    {
      int r = src1[3 * i + 0];
      int g = src1[3 * i + 1];
      int b = src1[3 * i + 2];
      dstU[i] =
	(ru * r + gu * g + bu * b + (256 << (15 - 1)) +
	 (1 << (15 - 7))) >> (15 - 6);
      dstV[i] =
	(rv * r + gv * g + bv * b + (256 << (15 - 1)) +
	 (1 << (15 - 7))) >> (15 - 6);
}}
