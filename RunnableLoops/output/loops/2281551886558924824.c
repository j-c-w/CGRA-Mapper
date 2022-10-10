#include <stdint.h>
#include <stdio.h>




typedef SoftFloat;
typedef __uint16_t uint16_t;
typedef SoftFloat AAC_FLOAT;

int
fn (int kx1, int e, AAC_FLOAT (*e_curr)[48], int p, int k, SoftFloat sum,
    const uint16_t * table)
{
  for (k = table[p]; k < table[p + 1]; k++)
    {
      e_curr[e][k - kx1] = sum;
    }
}
