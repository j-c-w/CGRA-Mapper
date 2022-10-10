#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * dst, int n, int len, int val)
{
  for (n = 0; n < len; n++)
    {
      dst[n] = val;
    }
}
