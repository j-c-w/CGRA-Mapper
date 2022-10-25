// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

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
	 cm[((0 * srcB + -1 * srcA + 5 * src0 + 5 * src1 + -1 * src2 +
	      0 * src3) + 4) >> 3] + 1) >> 1;
      dst[1 * dstStride] =
	((dst[1 * dstStride]) +
	 cm[((0 * srcA + -1 * src0 + 5 * src1 + 5 * src2 + -1 * src3 +
	      0 * src4) + 4) >> 3] + 1) >> 1;
      dst[2 * dstStride] =
	((dst[2 * dstStride]) +
	 cm[((0 * src0 + -1 * src1 + 5 * src2 + 5 * src3 + -1 * src4 +
	      0 * src5) + 4) >> 3] + 1) >> 1;
      dst[3 * dstStride] =
	((dst[3 * dstStride]) +
	 cm[((0 * src1 + -1 * src2 + 5 * src3 + 5 * src4 + -1 * src5 +
	      0 * src6) + 4) >> 3] + 1) >> 1;
      dst[4 * dstStride] =
	((dst[4 * dstStride]) +
	 cm[((0 * src2 + -1 * src3 + 5 * src4 + 5 * src5 + -1 * src6 +
	      0 * src7) + 4) >> 3] + 1) >> 1;
      dst[5 * dstStride] =
	((dst[5 * dstStride]) +
	 cm[((0 * src3 + -1 * src4 + 5 * src5 + 5 * src6 + -1 * src7 +
	      0 * src8) + 4) >> 3] + 1) >> 1;
      dst[6 * dstStride] =
	((dst[6 * dstStride]) +
	 cm[((0 * src4 + -1 * src5 + 5 * src6 + 5 * src7 + -1 * src8 +
	      0 * src9) + 4) >> 3] + 1) >> 1;
      dst[7 * dstStride] =
	((dst[7 * dstStride]) +
	 cm[((0 * src5 + -1 * src6 + 5 * src7 + 5 * src8 + -1 * src9 +
	      0 * src10) + 4) >> 3] + 1) >> 1;
      dst++;
      src++;
}}
