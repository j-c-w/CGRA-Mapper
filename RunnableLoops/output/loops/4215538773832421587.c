#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * exp, int cpl, int i, int k, int nb_groups)
{
  for (i = nb_groups, k = (nb_groups * 2) - cpl; i > 0; i--)
    {
      uint8_t exp1 = exp[i - cpl];
      exp[k--] = exp1;
      exp[k--] = exp1;
    }
}
