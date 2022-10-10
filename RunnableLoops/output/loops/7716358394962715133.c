#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const float *filter_coeff, int ncoeffs, float b, float a, int k, int j,
    int32_t * lfe_samples)
{
  for (k = 0; k < ncoeffs; k++)
    {
      a += filter_coeff[j * ncoeffs + k] * lfe_samples[-k];
      b += filter_coeff[255 - j * ncoeffs - k] * lfe_samples[-k];
    }
}
