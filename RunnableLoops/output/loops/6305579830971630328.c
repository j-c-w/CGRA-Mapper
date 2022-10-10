#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int w2, int16_t * dst, int i, int16_t * src1, int add, int shift,
    int16_t * src0)
{
  for (i = 0; i < w2; i++)
    {
      dst[2 * i] = ((int) (src0[i] + (unsigned) add)) >> shift;
      dst[2 * i + 1] = ((int) (src1[i] + (unsigned) add)) >> shift;
}}
