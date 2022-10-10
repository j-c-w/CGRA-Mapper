#include <stdint.h>
#include <stdio.h>






int
fn (int x, const float *asrc, float *dst, const float *msrc, int w)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = msrc[x] * asrc[x];
    }
}
