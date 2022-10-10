#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * exp, int cpl, int i, int k, int nb_groups)
{
  for (i = nb_groups, k = (nb_groups * 4) - cpl; i > 0; i--)
    {
      exp[k] = exp[k - 1] = exp[k - 2] = exp[k - 3] = exp[i - cpl];
      k -= 4;
    }
}
