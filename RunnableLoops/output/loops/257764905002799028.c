#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, int i, uint8_t bits[162], const uint8_t * lens)
{
  int idx = 0;
  for (j = 0; j < lens[i]; j++)
    {
      bits[idx] = i + 1;
      idx++;
    }
}
