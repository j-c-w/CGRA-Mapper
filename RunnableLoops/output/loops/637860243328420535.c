#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, int level[16], int total_coeff, int16_t * block,
    const uint8_t * scantable)
{
  for (; i < total_coeff; i++)
    {
      scantable--;
      ((int16_t *) block)[*scantable] = level[i];
    }
}
