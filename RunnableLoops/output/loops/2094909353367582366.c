#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * b0, int32_t * b2, int i, int32_t * b1, int width)
{
  for (i = 0; i < width; i++)
    {
      b1[i] =
	((unsigned) (b1[i]) +
	 ((int) (6497 * (b0[i] + (unsigned) b2[i]) + 2048) >> 12));
}}
