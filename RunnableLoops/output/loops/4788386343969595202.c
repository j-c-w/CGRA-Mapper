#include <stdint.h>
#include <stdio.h>






int
fn (float den, int i, float num, const float *u, float *v)
{
  for (i = 0; i < 40; i++)
    {
      num += v[i] * u[i];
      den += u[i] * u[i];
    }
}
