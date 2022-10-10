#include <stdint.h>
#include <stdio.h>






int
fn (const float *bsrc, float *dst, const float *osrc, const float *msrc,
    int w)
{
  for (int x = 0; x < w; x++)
    {
      const float invm = 1.f - msrc[x];
      const float r =
	((float) (bsrc[x] * invm) + (float) (msrc[x] * osrc[x] + 0.f)) + 0.f;
      dst[x] = r;
}}
