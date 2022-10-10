#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int64_t int64_t;

int
fn (int64_t b, int64_t a, int k, int j, int32_t * lfe_samples,
    const int32_t * filter_coeff)
{
  for (k = 0; k < 8; k++)
    {
      a += (int64_t) filter_coeff[j * 8 + k] * lfe_samples[-k];
      b += (int64_t) filter_coeff[255 - j * 8 - k] * lfe_samples[-k];
    }
}
