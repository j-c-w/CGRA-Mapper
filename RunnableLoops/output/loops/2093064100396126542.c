#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int *charmap, int x, int b_width, uint8_t * buf)
{
  for (x = 0; x < b_width; x++)
    {
      buf[y * b_width + x] = charmap[y * b_width + x];
    }
}
