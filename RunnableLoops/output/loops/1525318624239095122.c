#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int level, int i, uint16_t * run_table, int j, float *flevel_table, int l)
{
  for (j = 0; j < l; j++)
    {
      run_table[i] = j;
      flevel_table[i] = level;
      i++;
    }
}
