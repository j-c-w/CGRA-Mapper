#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, uint16_t * out, uint8_t * src, int bw2)
{
  for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint16_t *) src);
      src += 2;
    }
}
