// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_guided.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float maxval, int w, int dst_stride, int sub, int width, float *meanA,
    float *meanB, int src_stride, uint16_t * dst, const uint16_t * src)
{
  int i = 0;
  for (int j = 0; j < width; j++)
    {
      int x = i / sub * w + j / sub;
      dst[i * dst_stride + j] =
	meanA[x] * src[i * src_stride + j] + meanB[x] * maxval;
}}
