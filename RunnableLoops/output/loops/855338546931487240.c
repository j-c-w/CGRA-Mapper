#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int c, int i, int pitch)
{
  int out = 0;
  for (i = 0; i < c * 2; i++)
    {
      dst[out] = dst[out - pitch];
      out++;
    }
}
