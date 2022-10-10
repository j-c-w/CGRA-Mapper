#include <stdint.h>
#include <stdio.h>






int
fn (float scale, float *dst, const float *ref, float offset, const float *src,
    int w)
{
  for (int x = 0; x < w; x++)
    {
      const float factor = (ref[x] + offset) * scale;
      dst[x] = src[x] * factor;
}}
