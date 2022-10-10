#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * src, float *dst, int block_size, int j)
{
  for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
    }
}
