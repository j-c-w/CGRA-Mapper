#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t mask, int x, uint8_t * data, uint8_t * tmp)
{
  for (x = 0; x < 4; x++)
    {
      tmp[x] = data[mask & 3];
      mask >>= 2;
    }
}
