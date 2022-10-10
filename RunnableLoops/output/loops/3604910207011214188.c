#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *histogram, int x, int w, const uint8_t * src)
{
  for (x = 0; x < w; x++)
    {
      histogram[src[x]] += 1;
    }
}
