#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int j, int width, int16_t * band)
{
  for (j = 1; j < width; j++)
    {
      band[j] += band[j - 1];
    }
}
