#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int b, int i, int width, uint16_t * src_r, int g, uint16_t * src_g,
    uint16_t * src_b, int r)
{
  for (i = 0; i < width; i++)
    {
      r = src_r[i];
      g = src_g[i];
      b = src_b[i];
      src_r[i] = (r + g - 0x200) & 0x3FF;
      src_b[i] = (b + g - 0x200) & 0x3FF;
    }
}
