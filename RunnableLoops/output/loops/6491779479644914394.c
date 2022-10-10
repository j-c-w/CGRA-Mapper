#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int b1, int16_t * temp, int x, int b2, int16_t * b, int b0, const int w2)
{
  for (x = 1; x < w2; x++)
    {
      b2 =
	((unsigned) (temp[x]) +
	 ((int) (217 * (temp[x + w2 - 1] + (unsigned) temp[x + w2]) + 2048) >>
	  12));
      b1 =
	((unsigned) (temp[x + w2 - 1]) +
	 ((int) (6497 * (b0 + (unsigned) b2) + 2048) >> 12));
      b[2 * x - 1] = ~((~b1) >> 1);
      b[2 * x] = ~((~b2) >> 1);
      b0 = b2;
}}
