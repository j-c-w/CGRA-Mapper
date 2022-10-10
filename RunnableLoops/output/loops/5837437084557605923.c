#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dst, int w2, int32_t * src0, int i, int add, int32_t * src1,
    int shift)
{
  for (i = 0; i < w2; i++)
    {
      dst[2 * i] = ((int) (src0[i] + (unsigned) add)) >> shift;
      dst[2 * i + 1] = ((int) (src1[i] + (unsigned) add)) >> shift;
}}
