#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int j, int i, int coeff, int16_t * coeffs)
{
  for (i = 0; i < 4; i++)
    {
      coeffs[i + j * 4] = coeff;
    }
}
