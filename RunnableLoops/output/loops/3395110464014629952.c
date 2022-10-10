#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, uint16_t * tmp_cr, const int bit_depth, uint16_t * tmp_cb)
{
  for (j = 0; j < 8; j++)
    {
      tmp_cb[j] = tmp_cr[j] = 1 << (bit_depth - 1);
    }
}
