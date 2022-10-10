#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int sum, uint8_t * src)
{
  int square_sum = 0;
  for (x = 0; x < 8; x += 2)
    {
      sum += src[x];
      square_sum += src[x] * src[x];
    }
}
