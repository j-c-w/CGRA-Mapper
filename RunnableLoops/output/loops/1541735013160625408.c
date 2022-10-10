#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int block_size, int y, int x, uint8_t * src, int stride)
{
  int sum = 0;
  for (x = 0; x < block_size; x++)
    {
      sum += src[x + y * stride];
    }
}
