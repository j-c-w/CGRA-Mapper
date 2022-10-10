#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int pixel_x, int block_ptr, uint16_t * pixels, uint16_t colorA)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr] = colorA;
      block_ptr++;
    }
}
