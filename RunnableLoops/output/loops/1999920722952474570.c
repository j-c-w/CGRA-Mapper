#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dest_cb, uint8_t * dest_cr, int y, int x, int *linesize,
    int dcv, int dcu)
{
  for (x = 0; x < 8; x++)
    {
      dest_cb[x + y * linesize[1]] = dcu / 8;
      dest_cr[x + y * linesize[2]] = dcv / 8;
    }
}
