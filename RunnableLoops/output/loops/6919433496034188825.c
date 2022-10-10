#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (int i, const int n, const INTFLOAT * const window, INTFLOAT * out,
    const int n4, INTFLOAT * saved, const int n2, INTFLOAT * buf)
{
  for (i = 0; i < n4; i++)
    {
      out[n2 + n4 + i] =
	(int) (((int64_t) (buf[i + n2]) * (window[i + n - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (-saved[n2 - 1 - i]) * (window[i + 2 * n - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (-saved[n + n2 + i]) * (window[i + 3 * n - n4]) +
		0x40000000) >> 31);
}}
