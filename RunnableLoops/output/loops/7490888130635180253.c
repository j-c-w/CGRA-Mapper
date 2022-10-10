#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (unsigned int d, unsigned int c, int j, const int *coeffs, int s0,
    int pred_order, int32_t * decoded)
{
  int s1 = 0;
  for (j = 1; j < pred_order; j++)
    {
      s0 += c * d;
      d = decoded[j];
      s1 += c * d;
      c = coeffs[j];
    }
}
