#include <stdint.h>
#include <stdio.h>






int
fn (int len, int *tab0, int j, unsigned int tmp1, int *tab1,
    unsigned int tmp0)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tmp1 = tab1[j];
      tab0[j] =
	(((int64_t) ((int) (tmp0 + tmp1)) *
	  (int64_t) ((((int) ((0.70710678118654752440) * (1 << 23) + 0.5)))))
	 >> (23));
      tab1[j] =
	(((int64_t) ((int) (tmp0 - tmp1)) *
	  (int64_t) ((((int) ((0.70710678118654752440) * (1 << 23) + 0.5)))))
	 >> (23));
}}
