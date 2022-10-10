#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;

int
fn (const int8_t * par, int b, int8_t * par_mapped)
{
  for (; b >= 0; b--)
    {
      par_mapped[2 * b + 1] = par_mapped[2 * b] = par[b];
    }
}
