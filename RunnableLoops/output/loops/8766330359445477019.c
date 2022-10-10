#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * block)
{
  for (i = 0; i < 4; i++)
    {
      const unsigned z0 = block[i + 4 * 0] + (unsigned) block[i + 4 * 2];
      const unsigned z1 = block[i + 4 * 0] - (unsigned) block[i + 4 * 2];
      const unsigned z2 =
	(block[i + 4 * 1] >> 1) - (unsigned) block[i + 4 * 3];
      const unsigned z3 =
	block[i + 4 * 1] + (unsigned) (block[i + 4 * 3] >> 1);
      block[i + 4 * 0] = z0 + z3;
      block[i + 4 * 1] = z1 + z2;
      block[i + 4 * 2] = z1 - z2;
      block[i + 4 * 3] = z0 - z3;
}}
