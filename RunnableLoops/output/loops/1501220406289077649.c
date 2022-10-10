#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * dst, int i, int32_t by, int32_t ry, int32_t gy, int width,
    const uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      int b = src[i * 3 + 0];
      int g = src[i * 3 + 1];
      int r = src[i * 3 + 2];
      dst[i] =
	((ry * r + gy * g + by * b + (32 << (15 - 1)) +
	  (1 << (15 - 7))) >> (15 - 6));
}}
