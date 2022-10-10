#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int e, int32_t * res, int i, int n, int c, int order, int a,
    const int32_t * smp)
{
  for (i = order; i < n; i += 2)
    {
      int b = smp[i] - smp[i - 1];
      int d = b - a;
      int f = d - c;
      res[i] = f - e;
      a = smp[i + 1] - smp[i];
      c = a - b;
      e = c - d;
      res[i + 1] = e - f;
}}
