#include <stdint.h>
#include <stdio.h>






int
fn (const float *pole_coeffs, int i, int n, float gain,
    const float *zero_coeffs, float *out, const float *in, float tmp,
    float *mem)
{
  for (i = 0; i < n; i++)
    {
      tmp = gain * in[i] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
      out[i] = tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
      mem[1] = mem[0];
      mem[0] = tmp;
    }
}
