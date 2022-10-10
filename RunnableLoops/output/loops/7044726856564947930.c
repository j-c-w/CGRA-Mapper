#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * res, int i, int c, int n, int order, int a, const int32_t * smp)
{
  for (i = order; i < n; i += 2)
    {
      int b = smp[i] - smp[i - 1];
      int d = b - a;
      res[i] = d - c;
      a = smp[i + 1] - smp[i];
      c = a - b;
      res[i + 1] = c - d;
}}
