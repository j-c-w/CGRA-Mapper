#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t b, int i, uint8_t * src_r, uint8_t * src_g, int width, uint8_t g,
    uint8_t r, uint8_t * src_b)
{
  for (i = 0; i < width; i++)
    {
      r = src_r[i];
      g = src_g[i];
      b = src_b[i];
      src_r[i] = r + g - 0x80;
      src_b[i] = b + g - 0x80;
    }
}
