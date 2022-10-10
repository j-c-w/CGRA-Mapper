#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int dim, int cb, int off, int j, int *quants,
    const uint8_t aac_cb_range[12])
{
  int curidx = 0;
  for (j = 0; j < dim; j++)
    {
      curidx *= aac_cb_range[cb];
      curidx += quants[j] + off;
    }
}
