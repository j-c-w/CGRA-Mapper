#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef int64_t x86_reg;

int
fn (x86_reg i, int16_t * basis, int scale, int16_t * rem)
{
  for (i = 0; i < 8 * 8; i++)
    {
      rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
