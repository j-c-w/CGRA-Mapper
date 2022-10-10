#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * b2, int width, int16_t * b0, int16_t * b1)
{
  for (i = 0; i < width; i++)
    {
      b1[i] =
	((unsigned) (b1[i]) -
	 ((int) (113 * (b0[i] + (unsigned) b2[i]) + 64) >> 7));
}}
