#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int *src, int round, int i, int c, int k, int group,
    const uint16_t * offsets, int tmp, int shift, int *dest)
{
  for (k = offsets[i]; k < offsets[i + 1]; k++)
    {
      tmp =
	(int) (((int64_t) src[group * 128 + k] * c +
		(int64_t) 0x1000000000) >> 37);
      dest[group * 128 + k] += (tmp + (int64_t) round) >> shift;
}}
