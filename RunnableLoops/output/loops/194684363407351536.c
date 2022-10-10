#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int src_stride, int dst_stride, uint16_t * dst, float maxval,
    float *meanA, int width, float *meanB, const uint16_t * src, int sub,
    int w)
{
  int i = 0;
  for (int j = 0; j < width; j++)
    {
      int x = i / sub * w + j / sub;
      dst[i * dst_stride + j] =
	meanA[x] * src[i * src_stride + j] + meanB[x] * maxval;
}}
