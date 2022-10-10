#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * b4, int16_t * b3, int i, int16_t * b2, int width, int16_t * b0,
    int16_t * b1)
{
  for (i = 0; i < width; i++)
    {
      b2[i] =
	(int) (((unsigned) (b2[i]) +
		((int) (9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 8) >> 4)));
}}
