#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int src_stride, int dst_stride, float maxval, float *meanA, int width,
    float *meanB, uint8_t * dst, int sub, int w, const uint8_t * src)
{
  int i = 0;
  for (int j = 0; j < width; j++)
    {
      int x = i / sub * w + j / sub;
      dst[i * dst_stride + j] =
	meanA[x] * src[i * src_stride + j] + meanB[x] * maxval;
}}
