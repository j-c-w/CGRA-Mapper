#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float *histogram, const uint16_t * src, int x, int w)
{
  for (x = 0; x < w; x++)
    {
      histogram[src[x]] += 1;
    }
}
