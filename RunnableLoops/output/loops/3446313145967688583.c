#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, uint16_t * bufp, int end_x, int block_w)
{
  for (x = end_x; x < block_w; x++)
    {
      bufp[x] = bufp[end_x - 1];
    }
}
