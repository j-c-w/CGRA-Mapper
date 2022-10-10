#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * out, int i, int tile_width, uint32_t * in)
{
  for (i = 0; i < tile_width; i++)
    {
      out[0] = (in[i] >> 16) & 0xFF;
      out[1] = (in[i] >> 8) & 0xFF;
      out[2] = (in[i] >> 0) & 0xFF;
      out += 3;
    }
}
