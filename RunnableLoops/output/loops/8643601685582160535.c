#include <stdint.h>
#include <stdio.h>






int
fn (float offsetf, int x, const float *asrc, float *dst, const float *msrc,
    int w)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = ((msrc[x] - offsetf) * asrc[x]) + offsetf;
    }
}
