#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, int filter_length, const float *in,
    const float *filter_coeffs, int precision, int frac_pos, float v)
{
  int idx = 0;
  for (i = 0; i < filter_length;)
    {
      v += in[n + i] * filter_coeffs[idx + frac_pos];
      idx += precision;
      i++;
      v += in[n - i] * filter_coeffs[idx - frac_pos];
    }
}
