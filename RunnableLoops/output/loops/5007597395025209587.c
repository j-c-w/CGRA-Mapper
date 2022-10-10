#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (ptrdiff_t len, const float *c, float *sum, int n, const float *t)
{
  for (n = 0; n < len; n++)
    {
      const float cre = c[2 * n];
      const float cim = c[2 * n + 1];
      const float tre = t[2 * n];
      const float tim = t[2 * n + 1];
      sum[2 * n] += tre * cre - tim * cim;
      sum[2 * n + 1] += tre * cim + tim * cre;
}}
