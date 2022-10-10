#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, float *dst, int block_size, const uint8_t * src)
{
  for (j = 0; j < block_size; j++)
    {
      dst[j] = src[j];
    }
}
