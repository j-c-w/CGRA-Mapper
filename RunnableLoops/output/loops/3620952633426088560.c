#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int bw2, int i, uint8_t * src, uint32_t * out)
{
  for (i = 0; i < bw2; i++)
    {
      out[i] ^= *((uint32_t *) src);
      src += 4;
    }
}
