#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * obmc_weight, uint16_t * dst, int x, const uint8_t * src)
{
  for (x = 0; x < 16; x += 2)
    {
      dst[x] += src[x] * obmc_weight[x];
      dst[x + 1] += src[x + 1] * obmc_weight[x + 1];
    }
}
