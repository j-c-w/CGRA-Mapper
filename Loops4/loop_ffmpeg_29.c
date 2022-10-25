// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t dstStride, const uint8_t * src, ptrdiff_t srcStride,
    const uint8_t * cm, uint8_t * dst)
{
  const int w = 8;
  for (i = 0; i < w; i++)
    {
      const int srcB = src[-2 * srcStride];
      const int srcA = src[-1 * srcStride];
      const int src0 = src[0 * srcStride];
      const int src1 = src[1 * srcStride];
      const int src2 = src[2 * srcStride];
      const int src3 = src[3 * srcStride];
      const int src4 = src[4 * srcStride];
      const int src5 = src[5 * srcStride];
      const int src6 = src[6 * srcStride];
      const int src7 = src[7 * srcStride];
      const int src8 = src[8 * srcStride];
      const int src9 = src[9 * srcStride];
      const int src10 = src[10 * srcStride];
      dst[0 * dstStride] =
	((dst[0 * dstStride]) +
	 cm[((-1 * srcB + -2 * srcA + 96 * src0 + 42 * src1 + -7 * src2 +
	      0 * src3) + 64) >> 7] + 1) >> 1;
      dst[1 * dstStride] =
	((dst[1 * dstStride]) +
	 cm[((-1 * srcA + -2 * src0 + 96 * src1 + 42 * src2 + -7 * src3 +
	      0 * src4) + 64) >> 7] + 1) >> 1;
      dst[2 * dstStride] =
	((dst[2 * dstStride]) +
	 cm[((-1 * src0 + -2 * src1 + 96 * src2 + 42 * src3 + -7 * src4 +
	      0 * src5) + 64) >> 7] + 1) >> 1;
      dst[3 * dstStride] =
	((dst[3 * dstStride]) +
	 cm[((-1 * src1 + -2 * src2 + 96 * src3 + 42 * src4 + -7 * src5 +
	      0 * src6) + 64) >> 7] + 1) >> 1;
      dst[4 * dstStride] =
	((dst[4 * dstStride]) +
	 cm[((-1 * src2 + -2 * src3 + 96 * src4 + 42 * src5 + -7 * src6 +
	      0 * src7) + 64) >> 7] + 1) >> 1;
      dst[5 * dstStride] =
	((dst[5 * dstStride]) +
	 cm[((-1 * src3 + -2 * src4 + 96 * src5 + 42 * src6 + -7 * src7 +
	      0 * src8) + 64) >> 7] + 1) >> 1;
      dst[6 * dstStride] =
	((dst[6 * dstStride]) +
	 cm[((-1 * src4 + -2 * src5 + 96 * src6 + 42 * src7 + -7 * src8 +
	      0 * src9) + 64) >> 7] + 1) >> 1;
      dst[7 * dstStride] =
	((dst[7 * dstStride]) +
	 cm[((-1 * src5 + -2 * src6 + 96 * src7 + 42 * src8 + -7 * src9 +
	      0 * src10) + 64) >> 7] + 1) >> 1;
      dst++;
      src++;
}}
