#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t tmp, int i, int n, int32_t * right, int32_t * left)
{
  for (i = 0; i < n; i++)
    {
      tmp = left[i];
      left[i] = (tmp + right[i]) >> 1;
      right[i] = tmp - right[i];
    }
}
