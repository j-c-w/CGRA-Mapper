#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int x, int w2, int16_t * tmp, int16_t * b)
{
  for (; x < w2; x++)
    {
      b[2 * x] = (tmp[x] + 1) >> 1;
      b[2 * x + 1] =
	((int)
	 (((unsigned) (b[x + w2]) +
	   ((int)
	    (9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] +
	     8) >> 4))) + 1) >> 1;
}}
