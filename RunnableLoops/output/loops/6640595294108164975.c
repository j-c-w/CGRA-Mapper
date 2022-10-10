#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int x, int32_t * temp, const int w2, int32_t * b)
{
  for (x = 1; x < w2; x++)
    {
      temp[x] =
	((unsigned) (b[x]) -
	 ((int) (1817 * (b[x + w2 - 1] + (unsigned) b[x + w2]) + 2048) >>
	  12));
      temp[x + w2 - 1] =
	((unsigned) (b[x + w2 - 1]) -
	 ((int) (113 * (temp[x - 1] + (unsigned) temp[x]) + 64) >> 7));
}}
