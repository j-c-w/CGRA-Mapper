// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t dstStride, int16_t * tmp, const uint8_t * cm,
    uint8_t * dst)
{
  const int w = 8;
  for (i = 0; i < w; i++)
    {
      const int tmpB = tmp[-2 * 8];
      const int tmpA = tmp[-1 * 8];
      const int tmp0 = tmp[0 * 8];
      const int tmp1 = tmp[1 * 8];
      const int tmp2 = tmp[2 * 8];
      const int tmp3 = tmp[3 * 8];
      const int tmp4 = tmp[4 * 8];
      const int tmp5 = tmp[5 * 8];
      const int tmp6 = tmp[6 * 8];
      const int tmp7 = tmp[7 * 8];
      const int tmp8 = tmp[8 * 8];
      const int tmp9 = tmp[9 * 8];
      const int tmp10 = tmp[10 * 8];
      dst[0 * dstStride] =
	cm[((0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 +
	     -1 * tmp3) + 512) >> 10];
      dst[1 * dstStride] =
	cm[((0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 +
	     -1 * tmp4) + 512) >> 10];
      dst[2 * dstStride] =
	cm[((0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 +
	     -1 * tmp5) + 512) >> 10];
      dst[3 * dstStride] =
	cm[((0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 +
	     -1 * tmp6) + 512) >> 10];
      dst[4 * dstStride] =
	cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 +
	     -1 * tmp7) + 512) >> 10];
      dst[5 * dstStride] =
	cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 +
	     -1 * tmp8) + 512) >> 10];
      dst[6 * dstStride] =
	cm[((0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 +
	     -1 * tmp9) + 512) >> 10];
      dst[7 * dstStride] =
	cm[((0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 +
	     -1 * tmp10) + 512) >> 10];
      dst++;
      tmp++;
}}
