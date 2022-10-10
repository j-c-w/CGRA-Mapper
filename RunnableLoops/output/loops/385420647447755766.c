#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int n, int16_t * fir_coef, int m, int64_t filter, int16_t * src,
    int16_t * dest, int16_t * iir_coef)
{
  for (n = 1; n <= 10; n++)
    {
      filter -= fir_coef[n - 1] * src[m - n] - iir_coef[n - 1] * dest[m - n];
    }
}
