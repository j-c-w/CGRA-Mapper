#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int block_w, int end_x, uint8_t * bufp, int x)
{
  for (x = end_x; x < block_w; x++)
    {
      bufp[x] = bufp[end_x - 1];
    }
}
