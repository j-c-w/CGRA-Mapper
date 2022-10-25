// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv40dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const int w, const uint8_t * cm, int srcStride,
    const int SHIFT, const uint8_t * src, const int C2, const int C1,
    uint8_t * dst)
{
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
	cm[(srcB + src3 - 5 * (srcA + src2) + src0 * C1 + src1 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[1 * dstStride] =
	cm[(srcA + src4 - 5 * (src0 + src3) + src1 * C1 + src2 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[2 * dstStride] =
	cm[(src0 + src5 - 5 * (src1 + src4) + src2 * C1 + src3 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[3 * dstStride] =
	cm[(src1 + src6 - 5 * (src2 + src5) + src3 * C1 + src4 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[4 * dstStride] =
	cm[(src2 + src7 - 5 * (src3 + src6) + src4 * C1 + src5 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[5 * dstStride] =
	cm[(src3 + src8 - 5 * (src4 + src7) + src5 * C1 + src6 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[6 * dstStride] =
	cm[(src4 + src9 - 5 * (src5 + src8) + src6 * C1 + src7 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst[7 * dstStride] =
	cm[(src5 + src10 - 5 * (src6 + src9) + src7 * C1 + src8 * C2 +
	    (1 << (SHIFT - 1))) >> SHIFT];
      dst++;
      src++;
}}
