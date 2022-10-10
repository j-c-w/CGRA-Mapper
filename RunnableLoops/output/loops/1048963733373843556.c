#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int start_x, int x, uint8_t * bufp)
{
  for (x = 0; x < start_x; x++)
    {
      bufp[x] = bufp[start_x];
    }
}
