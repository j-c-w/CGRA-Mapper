#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * in, int i, int n, int filter_length, int precision,
    int frac_pos, const int16_t * filter_coeffs)
{
  int v = 0x4000;
  int idx = 0;
  for (i = 0; i < filter_length;)
    {
      v += in[n + i] * filter_coeffs[idx + frac_pos];
      idx += precision;
      i++;
      v += in[n - i] * filter_coeffs[idx - frac_pos];
    }
}
