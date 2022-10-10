#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * data, int x, uint8_t * tmp2, uint32_t mask, uint8_t * tmp)
{
  for (x = 0; x < 4; x++)
    {
      tmp[x] = (mask & 0x8000) ? *data++ : tmp2[x];
      mask <<= 1;
    }
}
