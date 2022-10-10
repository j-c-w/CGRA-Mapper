#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, const uint16_t * src, int block_size, float *dst)
{
  for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
    }
}
