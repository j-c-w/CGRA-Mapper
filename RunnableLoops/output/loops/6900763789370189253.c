#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (int i, const int n, const INTFLOAT * const window, INTFLOAT * out,
    const int n4, INTFLOAT * saved, const int n2, INTFLOAT * buf)
{
  for (i = 0; i < n2; i++)
    {
      out[n4 + i] =
	((buf[i]) * (window[i + n2 - n4])) +
	((-saved[n - 1 - i]) * (window[i + n2 + n - n4])) +
	((-saved[n + i]) * (window[i + n2 + 2 * n - n4])) +
	((saved[2 * n + n - 1 - i]) * (window[i + n2 + 3 * n - n4]));
    }
}
