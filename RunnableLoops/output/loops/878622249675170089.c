#include <stdint.h>
#include <stdio.h>






int
fn (int b, int *refl, int i, int *bp2, int *bp1, int j)
{
  for (j = 0; j <= i; j++)
    {
      bp1[j] =
	(int) ((bp2[j] -
		((int) (refl[i + 1] * (unsigned) bp2[i - j]) >> 12)) *
	       (unsigned) b) >> 12;
}}
