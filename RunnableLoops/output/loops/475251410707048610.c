#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t tmp, int i, int32_t * right, int n, int32_t * left)
{
  for (i = 0; i < n; i++)
    {
      tmp = right[i];
      right[i] = left[i] - right[i];
      left[i] = tmp + (right[i] >> 31);
    }
}
