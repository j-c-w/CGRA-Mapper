#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int k, uint16_t * g, int width, uint16_t * b, const int max, uint16_t * r)
{
  for (k = 0; k < width; k++)
    {
      b[k] = (b[k] + g[k]) & max;
      r[k] = (r[k] + g[k]) & max;
    }
}
