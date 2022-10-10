#include <stdint.h>
#include <stdio.h>






int
fn (int i, int i0, float *p, int i1)
{
  for (i = 1; i <= 4; i++)
    {
      p[i0 - i] = p[i0 + i];
      p[i1 + i - 1] = p[i1 - i - 1];
    }
}
