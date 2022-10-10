#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int32_t * right, int32_t * left, int shift, int nb_samples)
{
  for (i = 0; i < nb_samples; i++)
    {
      left[i] >>= shift;
      right[i] >>= shift;
    }
}
