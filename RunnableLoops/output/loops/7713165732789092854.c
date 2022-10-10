#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (int32_t gu, int32_t ru, int i, uint8_t * udst, int32_t by, uint8_t * ydst,
    int32_t ry, int32_t rv, int32_t gy, int32_t bu, uint8_t * vdst,
    const int chromWidth, int32_t gv, int32_t bv, const uint8_t * src)
{
  for (i = 0; i < chromWidth; i++)
    {
      unsigned int b = src[6 * i + 0];
      unsigned int g = src[6 * i + 1];
      unsigned int r = src[6 * i + 2];
      unsigned int Y = ((ry * r + gy * g + by * b) >> 15) + 16;
      unsigned int V = ((rv * r + gv * g + bv * b) >> 15) + 128;
      unsigned int U = ((ru * r + gu * g + bu * b) >> 15) + 128;
      udst[i] = U;
      vdst[i] = V;
      ydst[2 * i] = Y;
      b = src[6 * i + 3];
      g = src[6 * i + 4];
      r = src[6 * i + 5];
      Y = ((ry * r + gy * g + by * b) >> 15) + 16;
      ydst[2 * i + 1] = Y;
}}
