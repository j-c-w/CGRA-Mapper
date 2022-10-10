#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (const INTFLOAT * src1, int i, const INTFLOAT * src0, INTFLOAT * v)
{
  for (i = 0; i < 64; i++)
    {
      v[i] = src0[i] - src1[63 - i];
      v[127 - i] = src0[i] + src1[63 - i];
    }
}
