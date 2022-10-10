#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * b0, int32_t * b2, int i, int32_t * b4, int32_t * b1, int width,
    int32_t * b3)
{
  for (i = 0; i < width; i++)
    {
      b2[i] =
	(int) (((unsigned) (b2[i]) -
		((int) (9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
}}
