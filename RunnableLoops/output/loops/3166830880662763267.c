#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int i, int64_t iir, int j, int16_t * bptr_16, int16_t * dest,
    int16_t * perf_lpc, int64_t fir)
{
  for (j = 1; j <= 10; j++)
    {
      fir -= perf_lpc[j - 1] * bptr_16[i - j];
      iir += perf_lpc[j + 10 - 1] * dest[i - j];
    }
}
