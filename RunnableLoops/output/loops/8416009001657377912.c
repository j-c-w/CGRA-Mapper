#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int level_tab[65], int i, int start_i, int16_t * block,
    const uint8_t * perm_scantable, int run_tab[65])
{
  for (; i > start_i; i -= run_tab[i] + 1)
    {
      block[perm_scantable[i - 1]] = level_tab[i];
    }
}
