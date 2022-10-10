#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __int32_t int32_t;

int
fn (uint64_t count, const int32_t * res, int n, int i, int k)
{
  for (i = 0; i < n; i++)
    {
      int32_t v = -2 * res[i] - 1;
      v ^= v >> 31;
      count += (v >> k) + 1 + k;
    }
}
