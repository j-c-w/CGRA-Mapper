#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, unsigned int x, int i, int m, unsigned int nplanes,
    unsigned int bytes_per_line, uint8_t * scanline)
{
  for (i = nplanes - 1; i >= 0; i--)
    {
      v <<= 1;
      v += !!(scanline[i * bytes_per_line + (x >> 3)] & m);
    }
}
