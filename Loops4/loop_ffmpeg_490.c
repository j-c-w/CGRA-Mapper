// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int32_t gy, int32_t gv, uint8_t * udst, int32_t by, int i,
    const int chromWidth, int32_t gu, int32_t bu, int32_t ru, int32_t bv,
    uint8_t * ydst, uint8_t * vdst, const uint8_t * src, int32_t ry,
    int32_t rv)
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
