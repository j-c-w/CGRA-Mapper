// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

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
	((dst[0 * dstStride]) +
	 cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 +
	      0 * tmp3) + 64) >> 7] + 1) >> 1;
      dst[1 * dstStride] =
	((dst[1 * dstStride]) +
	 cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 +
	      0 * tmp4) + 64) >> 7] + 1) >> 1;
      dst[2 * dstStride] =
	((dst[2 * dstStride]) +
	 cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 +
	      0 * tmp5) + 64) >> 7] + 1) >> 1;
      dst[3 * dstStride] =
	((dst[3 * dstStride]) +
	 cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 +
	      0 * tmp6) + 64) >> 7] + 1) >> 1;
      dst[4 * dstStride] =
	((dst[4 * dstStride]) +
	 cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 +
	      0 * tmp7) + 64) >> 7] + 1) >> 1;
      dst[5 * dstStride] =
	((dst[5 * dstStride]) +
	 cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 +
	      0 * tmp8) + 64) >> 7] + 1) >> 1;
      dst[6 * dstStride] =
	((dst[6 * dstStride]) +
	 cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 +
	      0 * tmp9) + 64) >> 7] + 1) >> 1;
      dst[7 * dstStride] =
	((dst[7 * dstStride]) +
	 cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 +
	      0 * tmp10) + 64) >> 7] + 1) >> 1;
      dst++;
      tmp++;
}}
